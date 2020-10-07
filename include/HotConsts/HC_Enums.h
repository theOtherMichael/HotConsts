#pragma once

// Enumerations and maps to enums used throughout Hot Constants.

namespace HotConsts
{

// Enumeration representing an arithmetic literal type.
enum class literalType
{
    none,

    lit_int,
    lit_long,
    lit_longlong,
    lit_uint,
    lit_ulong,
    lit_ulonglong,

    lit_double,
    lit_float,
    lit_longdouble,
    
    lit_bool,

    lit_char,
    //lit_char8, //c++20
    lit_char16,
    lit_char32,
    lit_wchar
};

// Enumeration representing the base of a numeric literal.
enum class literalBase
{
    notapplicable,
    decimal,
    octal,
    hex,
    binary
};

// Map associating C++ types with their literalType values.
template <typename T>
struct literalTypeMap
{
    static const literalType value;
};



// Enumeration representing an arithmetic operation type.
enum class operationType
{
    // Priority Level 11
    multiply,
    divide,
    modulo,

    // Priority Level 10
    add,
    subtract,

    // Priority Level 9
    bitshift_left,
    bitshift_right,

    // Priority Level 8
    //compare_threeway, //c++20

    // Priority Level 7
    compare_lt,
    compare_ltoreq,
    compare_gt,
    compare_gtoreq,

    // Priority Level 6
    compare_eq,
    compare_neq,

    // Priority Level 5
    bitwise_AND,
    
    // Priority Level 4
    bitwise_XOR,
    
    // Priority Level 3
    bitwise_OR,

    // Priority Level 2
    logical_AND,
    
    // Priority Level 1
    logical_OR,
    
    // Priority Level 0
    none
};

// Map associating arithmetic operators with their priority level.  Higher levels take precedence.
extern std::map<operationType, size_t> operatorPriority;


// Enumeration representing an arithmetic unary operator type.
enum class unaryOperationType
{
    none,
    unary_plus,
    unary_minus,
    logical_NOT,
    bitwise_NOT
};


}
