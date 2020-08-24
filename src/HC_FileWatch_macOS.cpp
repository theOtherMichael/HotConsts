#include "HC_PCH.h"
#if defined(__APPLE__) && defined(__MACH__)

#include "HotConsts.h"

namespace HotConsts
{

bool HC_FileWatchRegistry::addWatch(std::string filepath)
{
    return false;
}


HC_FileWatchRegistry::~HC_FileWatchRegistry()
{
}


HC_FileWatchRegistry& _getWatchRegistry()
{
    // As long as no object references HC_FileWatchRegistry in its destructor, this
    // code should be safe.

    static HC_FileWatchRegistry instance;
    return instance;
}


}


#endif // macOS
