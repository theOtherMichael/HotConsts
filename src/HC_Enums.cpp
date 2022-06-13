#include "HotConsts/HC_Enums.h"

namespace HotConsts
{

template <typename T>
const literalType literalTypeMap<T>::value
	= literalType::none;

template <> const literalType literalTypeMap<int>::value
	= literalType::lit_int;
template <> const literalType literalTypeMap<long>::value
	= literalType::lit_long;
template <> const literalType literalTypeMap<long long>::value
	= literalType::lit_longlong;
template <> const literalType literalTypeMap<unsigned int>::value
	= literalType::lit_uint;
template <> const literalType literalTypeMap<unsigned long>::value
	= literalType::lit_ulong;
template <> const literalType literalTypeMap<unsigned long long>::value
	= literalType::lit_ulonglong;

template <> const literalType literalTypeMap<double>::value
	= literalType::lit_double;
template <> const literalType literalTypeMap<float>::value
	= literalType::lit_float;
template <> const literalType literalTypeMap<long double>::value
	= literalType::lit_longdouble;

template <> const literalType literalTypeMap<bool>::value
	= literalType::lit_bool;

template <> const literalType literalTypeMap<char>::value
	= literalType::lit_char;
//template <> const literalType literalTypeMap<char8_t>::value
//    = literalType::lit_char8; //c++20
template <> const literalType literalTypeMap<char16_t>::value
	= literalType::lit_char16;
template <> const literalType literalTypeMap<char32_t>::value
	= literalType::lit_char32;
template <> const literalType literalTypeMap<wchar_t>::value
	= literalType::lit_wchar;

std::map<operationType, size_t> operatorPriority
{
	{ operationType::multiply, 11 },
	{ operationType::divide, 11 },
	{ operationType::modulo, 11 },
	
	{ operationType::add, 10 },
	{ operationType::subtract, 10 },
	
	{ operationType::bitshift_left, 9 },
	{ operationType::bitshift_right, 9 },
	
	//{ operationType::compare_threeway, 8 }, //c++20
	
	{ operationType::compare_lt, 7 },
	{ operationType::compare_ltoreq, 7 },
	{ operationType::compare_gt, 7 },
	{ operationType::compare_gtoreq, 7 },
	
	{ operationType::compare_eq, 6 },
	{ operationType::compare_neq, 6 },
	
	{ operationType::bitwise_AND, 5 },
	
	{ operationType::bitwise_XOR, 4 },
	
	{ operationType::bitwise_OR, 3 },
	
	{ operationType::logical_AND, 2 },
	
	{ operationType::logical_OR, 1 },
	
	// "None" is a valid operationType given to expression tree roots, and get compared during arithmetic evaluation.
	{ operationType::none, 0 }
};

}
