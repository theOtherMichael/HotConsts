#if defined(__APPLE__) && defined(__MACH__)

#include "HotConsts/HotConsts.h"
#include <CoreServices/CoreServices.h>

// The length in seconds after a save event before the FSEvent callback is invoked.
#define MACOSLATENCY 0.1

// List of all filepaths being watched.
std::vector<std::string>& _watchedFilePaths()
{
	static std::vector<std::string>* instance = new std::vector<std::string>();
	return *instance;
}

// Pointer to the watcher thread (singleton).
std::thread*& _watcherThreadPtr()
{
	static std::thread** instance = new std::thread*(nullptr);
	return *instance;
}

// The current FSEventStreamRef.  This is supplanted as new files are added to the watch.
FSEventStreamRef& _currentFSEventStream()
{
	static FSEventStreamRef* instance = new FSEventStreamRef();
	return *instance;
}

// The CFRunLoopRef for the watcher thread's run loop.
CFRunLoopRef& _watcherRunLoopRef()
{
	static CFRunLoopRef* instance = new CFRunLoopRef();
	return *instance;
}

// Mutex used for locking the main thread while the watcher thread is starting up.
std::mutex& _watcherThreadInitMutex()
{
	static std::mutex* instance = new std::mutex();
	return *instance;
}

// Condition variable used for locking the main thread while the watcher thread is starting up.
std::condition_variable& _watcherThreadInitCV()
{
	static std::condition_variable* instance = new std::condition_variable;
	return *instance;
}

// Used with cv and mutex
bool& _isWatcherThreadInitialized()
{
	static bool* instance = new bool(false);
	return *instance;
}

// Callback invoked when a file is modified.
void FileChangeCallback_macOS(ConstFSEventStreamRef streamRef,
							 void *clientCallBackInfo,
							 size_t numEvents,
							 void *eventPaths,
							 const FSEventStreamEventFlags eventFlags[],
							 const FSEventStreamEventId eventIds[])
{
	char **paths = (char**)eventPaths;
	std::vector<std::string> handledPaths;

	for (int i=0; i<numEvents; i++) {
		if ((unsigned long)eventFlags[i] &
			(kFSEventStreamEventFlagItemCreated |
			 kFSEventStreamEventFlagItemRenamed |
			 kFSEventStreamEventFlagItemModified))
		{
			// The FSEvents API frequently returns several events for the same save action, so we have do debounce it.
			auto handledPathsIt = std::find(handledPaths.begin(),
											handledPaths.end(),
											paths[i]);
			if (handledPathsIt == handledPaths.end())
			{
				// Store this path for a debouncing check during this call.
				handledPaths.emplace_back(paths[i]);
				// Reload the file.
				printf("Hot Constants:  Reloading file \"%s\".\n", paths[i]);
				HotConsts::_reloadSrcFile(handledPaths.back());
			}
		}
	}
}

// Watcher thread
void WaitForFileChange_macOS()
{
	// 1. Create the run loop and store its reference globally
	_watcherRunLoopRef() = CFRunLoopGetCurrent();

	// 2. Schedule the first stream object with the run loop
	FSEventStreamScheduleWithRunLoop(_currentFSEventStream(), CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
	FSEventStreamStart(_currentFSEventStream());

	// 3. Notify the main thread that the stream can be safely modified from the main loop going forward
	{
		std::lock_guard<std::mutex> lk(_watcherThreadInitMutex());
		_isWatcherThreadInitialized() = true;
	}
	_watcherThreadInitCV().notify_one();

	// 4. Run the run loop.
	CFRunLoopRun(); // Loops here until CFRunLoopStop() is called from the main thread
}

namespace HotConsts
{

bool HC_FileWatchRegistry::addWatch(std::string filepath)
{
	// Only proceed if the file isn't already being watched.
	auto filePathIt = std::find(_watchedFilePaths().begin(),
								_watchedFilePaths().end(),
								filepath);
	if (filePathIt == _watchedFilePaths().end())
	{
		// Add the filepath to the watched list.
		_watchedFilePaths().emplace_back(filepath);

		// Create or update the watcher thread.
		if (_watcherThreadPtr())
		{
			// There's already a thread, so we're just updating it.

			// 1. Stop, unschedule, and release the current event stream.
			FSEventStreamStop(_currentFSEventStream());
			FSEventStreamInvalidate(_currentFSEventStream());
			FSEventStreamRelease(_currentFSEventStream());

			// 2. Create, schedule, and start a new event stream.
			// TODO: Should this be maintained as a vector of CFStringRefs?
			CFStringRef filepathsInCFStrs[_watchedFilePaths().size()];
			for (size_t i = 0; i < _watchedFilePaths().size(); i++)
			{
				filepathsInCFStrs[i] = CFStringCreateWithCString(kCFAllocatorDefault,
																 _watchedFilePaths().at(i).c_str(),
																 kCFStringEncodingUTF8);
			}
			CFArrayRef filepathsInCFArray = CFArrayCreate(NULL,
														  (const void **)&filepathsInCFStrs,
														  _watchedFilePaths().size(),
														  NULL);
			_currentFSEventStream() = FSEventStreamCreate(NULL,
														  &FileChangeCallback_macOS,
														  NULL,
														  filepathsInCFArray,
														  kFSEventStreamEventIdSinceNow,
														  MACOSLATENCY,
														  kFSEventStreamCreateFlagFileEvents
														  );
			CFRelease(filepathsInCFArray);
			for (size_t i = 0; i <_watchedFilePaths().size(); i++)
			{
				CFRelease(filepathsInCFStrs[i]);
			}

			FSEventStreamScheduleWithRunLoop(_currentFSEventStream(), _watcherRunLoopRef(), kCFRunLoopDefaultMode);
			FSEventStreamStart(_currentFSEventStream());
		}
		else
		{
			// There's no thread yet, so we're creating it.

			// 1. Create the first event stream.
			CFStringRef filepathAsCFStr = CFStringCreateWithCString(kCFAllocatorDefault,
																	filepath.c_str(),
																	kCFStringEncodingUTF8);
			CFArrayRef filepathAsCFArray = CFArrayCreate(NULL, (const void **)&filepathAsCFStr, 1, NULL);

			_currentFSEventStream() = FSEventStreamCreate(NULL,
														  &FileChangeCallback_macOS,
														  NULL,
														  filepathAsCFArray,
														  kFSEventStreamEventIdSinceNow,
														  MACOSLATENCY,
														  kFSEventStreamCreateFlagFileEvents
														  );
			CFRelease(filepathAsCFArray);
			CFRelease(filepathAsCFStr);

			// 2. Create the watcher thread.
			_watcherThreadPtr() = new std::thread(WaitForFileChange_macOS);

			// 3. Wait until the first stream is scheduled and started in the watcher thread.
			std::unique_lock<std::mutex> lk(_watcherThreadInitMutex());
			_watcherThreadInitCV().wait(lk, []{return _isWatcherThreadInitialized();});
		}
	}

	return true;
}

HC_FileWatchRegistry::~HC_FileWatchRegistry()
{
	if(_watcherThreadPtr())
	{
		// 1. Stop, unschedule, and release current stream.
		FSEventStreamStop(_currentFSEventStream());
		FSEventStreamInvalidate(_currentFSEventStream());
		FSEventStreamRelease(_currentFSEventStream());

		// 2. Abort the watcher thread's run loop, and join it.
		CFRunLoopStop(_watcherRunLoopRef());
		_watcherThreadPtr()->join();
		delete _watcherThreadPtr();
	}
}

HC_FileWatchRegistry& _getWatchRegistry()
{
	// As long as no object references HC_FileWatchRegistry in its destructor, this code should be safe.
	static HC_FileWatchRegistry instance;
	return instance;
}

}

#endif // macOS
