#include "HC_PCH.h"
#ifdef _WIN32

#include "HotConsts.h"

std::vector<std::wstring>& _watchedDirPaths()
{
	static std::vector<std::wstring>* instance
		= new std::vector<std::wstring>();
	return *instance;
};
std::vector<std::vector<std::string>>& _watchedFilepathsPerDir()
{
	static std::vector<std::vector<std::string>>* instance
		= new std::vector<std::vector<std::string>>();
	return *instance;
};
std::vector<std::vector<std::wstring>>& _watchedFilenamesPerDir()
{
	static std::vector<std::vector<std::wstring>>* instance
		= new std::vector<std::vector<std::wstring>>();
	return *instance;
};
std::deque<std::mutex>& _watchedDirMutexes()
{
	static std::deque<std::mutex>* instance
		= new std::deque<std::mutex>();
	return *instance;
};


std::vector<HANDLE>& _openDirHandles()
{
	static std::vector<HANDLE>* instance
		= new std::vector<HANDLE>();
	return *instance;
};
std::vector<std::thread>& _watchThreads()
{
	static std::vector<std::thread>* instance
		= new std::vector<std::thread>();
	return *instance;
};


// TODO: Reevaluate the portability of this?
#ifdef UNICODE
#define tcout std::wcout
#define tstring std::wstring
#else
#define tcout std::cout
#define tstring std::string
#endif


void printLastError(DWORD errorcode)
{
	LPVOID lpMsgBuf;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorcode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	tcout << L"Error " << errorcode << L": " << tstring((LPTSTR)lpMsgBuf) << std::endl;
}


//std::wstring changeActionToWString(DWORD actionID)
//{
//	switch (actionID)
//	{
//	case FILE_ACTION_ADDED:
//		return L"FILE_ACTION_ADDED";
//		break;
//	case FILE_ACTION_REMOVED:
//		return L"FILE_ACTION_REMOVED";
//		break;
//	case FILE_ACTION_MODIFIED:
//		return L"FILE_ACTION_MODIFIED";
//		break;
//	case FILE_ACTION_RENAMED_OLD_NAME:
//		return L"FILE_ACTION_RENAMED_OLD_NAME";
//		break;
//	case FILE_ACTION_RENAMED_NEW_NAME:
//		return L"FILE_ACTION_RENAMED_NEW_NAME";
//		break;
//	}
//}


void WaitForDirChange_Win32(size_t index)
{
	char buffer[1024];
	size_t nextBufferPos = 0;
	FILE_NOTIFY_INFORMATION* notifyInfo;
	DWORD bytesReturned;

	// Sleep until a file was changed in the directory.
	while (ReadDirectoryChangesW(_openDirHandles().at(index),
								 buffer,
								 sizeof(buffer),
								 FALSE,
								 FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_FILE_NAME,
								 &bytesReturned,
								 NULL,
								 NULL))
	{
		do
		{
			notifyInfo = (FILE_NOTIFY_INFORMATION*)&buffer[nextBufferPos];
			nextBufferPos += notifyInfo->NextEntryOffset;

			// Display information about action
			//std::wcout << L"Name: \""
			//	<< std::wstring(notifyInfo->FileName,
			//					notifyInfo->FileNameLength / sizeof(wchar_t))
			//	<< L"\", Action: " << changeActionToWString(notifyInfo->Action) << std::endl;

			if (notifyInfo->Action == FILE_ACTION_MODIFIED || notifyInfo->Action == FILE_ACTION_RENAMED_NEW_NAME)
			{
				_watchedDirMutexes().at(index).lock(); // TODO: use safer locks!

				// See if the file that's changed is one of the ones we're tracking.
				auto changedFilenameIt =
					std::find(_watchedFilenamesPerDir().at(index).begin(),
							  _watchedFilenamesPerDir().at(index).end(),
							  std::wstring(notifyInfo->FileName,
										   notifyInfo->FileNameLength / sizeof(wchar_t)));

				if (changedFilenameIt != _watchedFilenamesPerDir().at(index).end())
				{
					std::wcout << L"Hot Constants:  Reloading file \"" << *changedFilenameIt <<
						"\"." << std::endl;

					HotConsts::_reloadSrcFile(
						_watchedFilepathsPerDir().at(index).at(
							changedFilenameIt - _watchedFilenamesPerDir().at(index).begin()));
				}

				_watchedDirMutexes().at(index).unlock();
			}

		} while (notifyInfo->NextEntryOffset != 0);

		nextBufferPos = 0;
	}

	// Report if the loop wasn't terminated on purpose.

	DWORD errorcode = GetLastError();
	if (errorcode != ERROR_OPERATION_ABORTED)
	{
		printLastError(errorcode);
	}
}



namespace HotConsts
{

bool HC_FileWatchRegistry::addWatch(std::string filepath)
{
	// Convert filepath into a wide string for the sake of the Win32 API.
	const char*				filepath_cstr			= filepath.c_str();
	size_t					filepath_len			= strlen(filepath_cstr) + 1;
	std::vector<wchar_t>	filepath_wcstr			(filepath_len);
	size_t					numOfCharsConverted;
	std::mbstate_t			outState				= std::mbstate_t();

	mbsrtowcs_s(&numOfCharsConverted,	//unused
				&filepath_wcstr[0], filepath_len,
				&filepath_cstr, filepath_len,
				&outState);				//unused

	std::wstring filepath_wstr(filepath_wcstr.data()); // Ta-da!


	// Split the filepath into filename and dirpath strings.
	size_t finalSlashPos = filepath_wstr.rfind(L"\\");
	if (finalSlashPos + 1 >= filepath_wstr.length()) //TODO: see if this check shouldn't be removed.
	{
		std::wcout << L"Hot Constants:  Error: HC_FileWatchRegistry::addWatch() "
			"was passed invalid filepath \"" << filepath_wstr << L"\"." << std::endl;
		return false;
	}
	auto filename = filepath_wstr.substr(finalSlashPos + 1);
	auto dirpath = filepath_wstr.substr(0, finalSlashPos);


	// Check whether this directory already has a thread watching it.
	auto dirPathIt = std::find(_watchedDirPaths().begin(),
							   _watchedDirPaths().end(),
							   dirpath);
	auto index = dirPathIt - _watchedDirPaths().begin();

	if (dirPathIt == _watchedDirPaths().end())
	{
		// Directory isn't monitored yet: launch a thread.

		// Open directory handle
		auto directoryHandle =
			CreateFile(dirpath.c_str(),
					   FILE_LIST_DIRECTORY,
					   FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
					   NULL,
					   OPEN_EXISTING,
					   FILE_FLAG_BACKUP_SEMANTICS,
					   NULL);

		if (directoryHandle == INVALID_HANDLE_VALUE)
		{
			std::wcout << L"Hot Constants:  Error opening handle to directory \""
				<< dirpath << L"\".  Changes to \"" << filename << L"\" will not trigger "
				"reload.";
			printLastError(GetLastError());
			return false;
		}
		else
		{
			// Register folder
            // TODO: Confirm that this is thread-safe.
			_watchedDirPaths().emplace_back(dirpath);
			_openDirHandles().emplace_back(directoryHandle);
			_watchedFilepathsPerDir().emplace_back();
			_watchedFilenamesPerDir().emplace_back();
			_watchedDirMutexes().emplace_back();
			
			// Register file watch
			_watchedFilepathsPerDir().back().emplace_back(filepath);
			_watchedFilenamesPerDir().back().emplace_back(filename);

			// Create watch thread
			_watchThreads().emplace_back(std::thread(WaitForDirChange_Win32, index));

			return true;
		}
	}
	else
	{
		// The thread already exists: append the new filename to its watch list.
		// If the file is already watched, skip this.

		auto registeredFilenameIt = std::find(_watchedFilenamesPerDir().at(index).begin(),
											  _watchedFilenamesPerDir().at(index).end(),
											  filename);
		if (registeredFilenameIt == _watchedFilenamesPerDir().at(index).end())
		{
			_watchedDirMutexes().at(index).lock();
			_watchedFilepathsPerDir().at(index).emplace_back(filepath);
			_watchedFilenamesPerDir().at(index).emplace_back(filename);
			_watchedDirMutexes().at(index).unlock();
		}
		return true;
	}

	return false;
}


HC_FileWatchRegistry::~HC_FileWatchRegistry()
{
	// Cancel waits
	for (auto handleIt : _openDirHandles())
	{
		CancelIoEx(handleIt, NULL);
	}

	// Join threads
	for (auto threadIt = _watchThreads().begin();
		 threadIt != _watchThreads().end();
		 ++threadIt)
	{
		threadIt->join();
	}

	// Close open directory handles
	for (auto handleIt : _openDirHandles())
	{
		CloseHandle(handleIt);
	}
}


HC_FileWatchRegistry& _getWatchRegistry()
{
	// As long as no object references HC_FileWatchRegistry in its destructor, this
	// code should be safe.

	static HC_FileWatchRegistry instance;
	return instance;
}


}


#endif // _WIN32
