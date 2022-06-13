#pragma once
#include <string>

namespace HotConsts
{

class HC_FileWatchRegistry
{
public:
	bool addWatch(std::string file);
	
	~HC_FileWatchRegistry();
};

HC_FileWatchRegistry& _getWatchRegistry();

}
