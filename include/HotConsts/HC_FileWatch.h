#pragma once
#include "HC_PCH.h"

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
