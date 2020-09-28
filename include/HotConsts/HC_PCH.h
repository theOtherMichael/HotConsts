#pragma once

#include <fstream>
#include <iostream>

#include <string>
#include <sstream>
#include <string_view>
#include <vector>
#include <deque>
#include <map>

#include <thread>
#include <mutex>
#include <atomic>

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#if defined(__APPLE__) && defined(__MACH__)
#include <CoreServices/CoreServices.h>
#endif // macOS
