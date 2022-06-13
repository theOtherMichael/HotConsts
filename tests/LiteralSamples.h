#pragma once
#include <HotConsts/HotConsts.h>
#include <vector>

/*
	Vectors containing examples of every kind of literal HotConsts needs to handle.
	These are declared extern so that they can be initialized with initializer lists.
*/

// Int literals
extern std::vector<std::string> intLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> intLiteralIdentities;
extern std::vector<int> intLiteralConversions;

// Long literals
extern std::vector<std::string> longLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> longLiteralIdentities;
extern std::vector<long> longLiteralConversions;

// Long long literals
extern std::vector<std::string> longlongLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> longlongLiteralIdentities;
extern std::vector<long long> longlongLiteralConversions;

// Unsigned int literals
extern std::vector<std::string> uintLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> uintLiteralIdentities;
extern std::vector<unsigned int> uintLiteralConversions;

// Unsigned long literals
extern std::vector<std::string> ulongLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> ulongLiteralIdentities;
extern std::vector<unsigned long> ulongLiteralConversions;

// Unsigned long long literals
extern std::vector<std::string> ulonglongLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> ulonglongLiteralIdentities;
extern std::vector<unsigned long long> ulonglongLiteralConversions;


// Double literals
extern std::vector<std::string> doubleLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> doubleLiteralIdentities;
extern std::vector<double> doubleLiteralConversions;

// Float literals
extern std::vector<std::string> floatLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> floatLiteralIdentities;
extern std::vector<float> floatLiteralConversions;

// Long double literals
extern std::vector<std::string> longDoubleLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> longDoubleLiteralIdentities;
extern std::vector<long double> longDoubleLiteralConversions;


// Char literals
extern std::vector<std::string> charLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> charLiteralIdentities;
extern std::vector<char> charLiteralConversions;
extern std::vector<std::string> char8Literals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> char8LiteralIdentities;
extern std::vector<char> char8LiteralConversions; //TODO: Change type to char8_t in c++20
extern std::vector<std::string> char16Literals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> char16LiteralIdentities;
extern std::vector<char16_t> char16LiteralConversions;
extern std::vector<std::string> char32Literals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> char32LiteralIdentities;
extern std::vector<char32_t> char32LiteralConversions;
extern std::vector<std::string> wcharLiterals;
extern std::vector<std::pair<HotConsts::literalType, HotConsts::literalBase>> wcharLiteralIdentities;
extern std::vector<wchar_t> wcharLiteralConversions;


// Operators
extern std::vector<std::string> operatorTokens;
extern std::vector<HotConsts::operationType> operatorIdentities;
