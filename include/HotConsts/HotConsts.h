#pragma once
#include "HotConsts/HC_ArithmeticEval.h"
#include "HotConsts/HC_FileWatch.h"
#include "HotConsts/HC_Atomic.h"
#include <deque>

/*
	HotConsts.h
	To utilize Hot Constants, include this header into your source code. You 
	can then use the HC() and HCEX() macros to define your constants.
	
	Define HC_RELOADING_ON in debug builds to make constants reloadable in those configurations.
	In builds where this is not defined, the macros will expand into regular hard-coded constants.
*/

namespace HotConsts
{

// Gets the deque of pointers to type T hot constants.
template <typename T>
std::deque<HC_Atomic<T>>& _getHCDequeOfType()
{
	static auto instance = new std::deque<HC_Atomic<T>>();
	return *instance;
}

// Reloads a hot constant with the evaluation of the provided string.
template <typename T> 
bool _reloadHotConst(std::string& stringExpr, size_t hcTypedDequeIndex)
{
	std::pair<bool, T> evalResult = _evalArithmeticExpression<T>(stringExpr);

	if (evalResult.first)
	{
		_getHCDequeOfType<T>().at(hcTypedDequeIndex) = evalResult.second;
		return true;
	}
	else
	{
		return false;
	}
}

// Function pointer to a specific template of _reloadHotConst().
typedef bool (*hcReloadFn)(std::string&, size_t);

// A source file name and constant name pair.  Uniquely identifies a hot constant in source code.
using hcSrcOrigin = std::pair<std::string, std::string>;
// Gets an std::map associating a hot constant with its reload function.
extern std::map<hcSrcOrigin, std::tuple<std::string, hcReloadFn, unsigned int>>& _getReloadMap();

// Recursively erases comments from a line of source code.
std::string _stripComments(std::string srcLine, bool& startsInMultiline);

// Reload all of the hot constants in a given source file.
void _reloadSrcFile(const std::string& expr);

// Instantiate and register a hot constant with the reload mechanism.
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, T>::type* = nullptr>
HotConsts::HC_Atomic<T>& _registerHotConst(const char* file, const char* name, const char* type)
{
	_getHCDequeOfType<T>().emplace_back();
	_getReloadMap()[std::pair(std::string(file), std::string(name))] =
		 std::tuple(std::string(type), &_reloadHotConst<T>, _getHCDequeOfType<T>().size() - 1);

	_getWatchRegistry().addWatch(file);

	// Return reference to variable
	return _getHCDequeOfType<T>().back();
}

}

#ifdef HC_RELOADING_ON
#define HC(type, name) \
const HotConsts::HC_Atomic<type>& name = \
HotConsts::_registerHotConst<type>(__FILE__, #name, #type)
#define HCEX(type, name) extern const HotConsts::HC_Atomic<type>& name
#else
#define HC(type, name) const type name
#define HCEX(type, name) extern const type name
#endif
