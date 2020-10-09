#include "HC_PCH.h"
#include "HC_ArithmeticEval.h"

namespace HotConsts
{

#if HOTCONSTS_INSTRUMENTATION
int _nodeCount = 0;
#endif


// Expression Tree Stuff ===============================================================================================


bool ETNode::operator<(const ETNode& other) const
{
    if (priority == other.priority)
        return (operatorPriority[opType] < operatorPriority[other.opType]);
    else
        return priority < other.priority;
}

bool ETNode::operator>=(const ETNode& other) const
{
    if (priority == other.priority)
        return (operatorPriority[opType] >= operatorPriority[other.opType]);
    else
        return priority >= other.priority;
}


ETNode* _newETLeaf(std::string& lit)
{
    ETNode* returnVal = nullptr;
    auto [type, base] = _identifyArithmeticLiteral(lit);
    
    try // Catches invalid_argument exceptions
    {
        switch (type)
        {
            case literalType::lit_int:
            {
                try
                {
                    int val = _convertLiteralTo_int(lit, base);
                    returnVal = new ETLeaf<int>(literalType::lit_int, val);
                }
                catch (std::out_of_range& e)
                {
                    // Attempt as long
                    try
                    {
                        long val = _convertLiteralTo_long(lit, base);
                        returnVal = new ETLeaf<long>(literalType::lit_long, val);
                    }
                    catch (std::out_of_range& e)
                    {
                        // Attempt as long long
                        try
                        {
                            long long val = _convertLiteralTo_longlong(lit, base);
                            returnVal = new ETLeaf<long long>(literalType::lit_longlong, val);
                        }
                        catch (std::out_of_range& e)
                        {
                            // There's no promotion possible per the C++ standard.
                            std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                                "\" is too large for any signed integral type." << std::endl;
                        }
                    }
                }
            }
                break;
            case literalType::lit_long:
            {
                try
                {
                    long val = _convertLiteralTo_long(lit, base);
                    returnVal = new ETLeaf<long>(literalType::lit_long, val);
                }
                catch (std::out_of_range& e)
                {
                    // Attempt as long long
                    try
                    {
                        long long val = _convertLiteralTo_longlong(lit, base);
                        returnVal = new ETLeaf<long long>(literalType::lit_longlong, val);
                    }
                    catch (std::out_of_range& e)
                    {
                        // There's no promotion possible per the C++ standard.
                        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                            "\" is too large for any signed integral type." << std::endl;
                    }
                }
            }
                break;
            case literalType::lit_longlong:
            {
                try
                {
                    long long val = _convertLiteralTo_longlong(lit, base);
                    returnVal = new ETLeaf<long long>(literalType::lit_longlong, val);
                }
                catch (std::out_of_range& e)
                {
                    // There's no promotion possible per the C++ standard.
                    std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                        "\" is too large for any signed integral type." << std::endl;
                }
            }
                break;
            case literalType::lit_uint:
            {
                try
                {
                    unsigned int val = _convertLiteralTo_uint(lit, base);
                    returnVal = new ETLeaf<unsigned int>(literalType::lit_uint, val);
                }
                catch (std::out_of_range& e)
                {
                    // Attempt as unsigned long
                    try
                    {
                        unsigned long val = _convertLiteralTo_ulong(lit, base);
                        returnVal = new ETLeaf<unsigned long>(literalType::lit_ulong, val);
                    }
                    catch (std::out_of_range& e)
                    {
                        // Attempt as unsigned long long
                        try
                        {
                            unsigned long long val = _convertLiteralTo_ulonglong(lit, base);
                            returnVal = new ETLeaf<unsigned long long>(literalType::lit_ulonglong, val);
                        }
                        catch (std::out_of_range& e)
                        {
                            // There's no promotion possible per the C++ standard.
                            std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                                "\" is too large for any unsigned integral type." << std::endl;
                        }
                    }
                }
            }
                break;
            case literalType::lit_ulong:
            {
                try
                {
                    unsigned long val = _convertLiteralTo_ulong(lit, base);
                    returnVal = new ETLeaf<unsigned long>(literalType::lit_ulong, val);
                    
                }
                catch (std::out_of_range& e)
                {
                    // Attempt as unsigned long long
                    try
                    {
                        unsigned long long val = _convertLiteralTo_ulonglong(lit, base);
                        returnVal = new ETLeaf<unsigned long long>(literalType::lit_ulonglong, val);
                    }
                    catch (std::out_of_range& e)
                    {
                        // There's no promotion possible per the C++ standard.
                        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                            "\" is too large for any unsigned integral type." << std::endl;
                    }
                }
            }
                break;
            case literalType::lit_ulonglong:
            {
                try
                {
                    unsigned long long val = _convertLiteralTo_ulonglong(lit, base);
                    returnVal = new ETLeaf<unsigned long long>(literalType::lit_ulonglong, val);
                }
                catch (std::out_of_range& e)
                {
                    // There's no promotion possible per the C++ standard.
                    std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                        "\" is too large for any unsigned integral type." << std::endl;
                }
            }
                break;
                
                
            case literalType::lit_double:
            {
                try
                {
                    double val = _convertLiteralTo_double(lit, base);
                    returnVal = new ETLeaf<double>(literalType::lit_double, val);
                }
                catch (std::out_of_range& e)
                {
                    // In some library implementations, this situation can be caused by underflows.
                    std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                        "\" falls out of range for type 'double'." << std::endl;
                }
            }
                break;
            case literalType::lit_float:
            {
                try
                {
                    float val = _convertLiteralTo_float(lit, base);
                    returnVal = new ETLeaf<float>(literalType::lit_float, val);
                }
                catch (std::out_of_range& e)
                {
                    // In some library implementations, this situation can be caused by underflows.
                    std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                        "\" falls out of range for type 'float'." << std::endl;
                }
            }
                break;
            case literalType::lit_longdouble:
            {
                try
                {
                    long double val = _convertLiteralTo_longdouble(lit, base);
                    returnVal = new ETLeaf<long double>(literalType::lit_longdouble, val);
                }
                catch (std::out_of_range& e)
                {
                    // In some library implementations, this situation can be caused by underflows.
                    std::cout << "Hot Constants:  Conversion failure: Literal value \"" << lit <<
                        "\" falls out of range for type 'long double'." << std::endl;
                }
            }
                break;
                
                
            case literalType::lit_char:
            {
                try
                {
                    char val = _convertLiteralTo_char(lit);
                    returnVal = new ETLeaf<char>(literalType::lit_char, val);
                }
                catch (std::out_of_range& e)
                {
                    std::cout << "Hot Constants:  Conversion failure: Escape sequence in \"" << lit <<
                        "\" falls out of range for type 'char'." << std::endl;
                }
            }
                break;
            case literalType::lit_char8: //c++17
            {
                try
                {
                    char val = _convertLiteralTo_char(lit);
                    returnVal = new ETLeaf<char>(literalType::lit_char8, val); //TODO: Change to char8_t in c++20
                }
                catch (std::out_of_range& e)
                {
                    std::cout << "Hot Constants:  Conversion failure: Escape sequence in \"" << lit <<
                        "\" falls out of range for type 'char'." << std::endl;
                }
            }
                break;
            case literalType::lit_char16:
            {
                try
                {
                    char16_t val = _convertLiteralTo_char16(lit);
                    returnVal = new ETLeaf<char16_t>(literalType::lit_char16, val);
                }
                catch (std::out_of_range& e)
                {
                    std::cout << "Hot Constants:  Conversion failure: Escape sequence in \"" << lit <<
                        "\" falls out of range for type 'char16_t'." << std::endl;
                }
            }
                break;
            case literalType::lit_char32:
            {
                try
                {
                    char32_t val = _convertLiteralTo_char32(lit);
                    returnVal = new ETLeaf<char32_t>(literalType::lit_char32, val);
                }
                catch (std::out_of_range& e)
                {
                    std::cout << "Hot Constants:  Conversion failure: Escape sequence in \"" << lit <<
                        "\" falls out of range for type 'char32_t'." << std::endl;
                }
            }
                break;
            case literalType::lit_wchar:
            {
                try
                {
                    wchar_t val = _convertLiteralTo_wchar(lit);
                    returnVal = new ETLeaf<wchar_t>(literalType::lit_wchar, val);
                }
                catch (std::out_of_range& e)
                {
                    std::cout << "Hot Constants:  Conversion failure: Escape sequence in \"" << lit <<
                        "\" falls out of range for type 'wchar_t'." << std::endl;
                }
            }
                break;
                
                
                
            case literalType::lit_bool:
            {
                bool val = _convertLiteralTo_bool(lit);
                returnVal = new ETLeaf<bool>(literalType::lit_bool, val);
            }
                break;
                
            case literalType::none:
            {
                std::cout << "Hot Constants:  _newETLeaf() was passed a token which didn't contain an identifiable literal.  "
                "Token: \"" << lit << "\"" << std::endl;
            }
                break;
        }
    }
    catch (std::invalid_argument& e) // TODO: Fix this error message, which is trash.
    {
        // Handle a bad literal.
        std::cout << "Hot Constants:  _newETLeaf() was passed a token which was identifed as a literal but was identified"
            " as an invalid argument by a string conversion function.  Token: " << lit << ", identified as literalType: "
            << int(type) << std::endl;
    }

    return returnVal;
}


void _popETNode(ETNode* node)
{
    if (auto op = dynamic_cast<ETOperator*>(node))
    {
        if (op->rchild != nullptr)
            _popETNode(op->rchild);
        if (op->lchild != nullptr)
            _popETNode(op->lchild);
    }
    delete node;
}


// Helper macro that evaluates an ETOperator to a value.
#define VALID_OPERATION(Left_T, Right_T) \
{ \
    /* The following operations should return a bool type. */\
    if (op->opType == operationType::compare_lt || \
        op->opType == operationType::compare_ltoreq || \
        op->opType == operationType::compare_gt || \
        op->opType == operationType::compare_gtoreq || \
        op->opType == operationType::compare_eq || \
        op->opType == operationType::compare_neq || \
        op->opType == operationType::logical_AND || \
        op->opType == operationType::logical_OR) \
    { \
        auto evaluatedValue = _evaluateOp<Left_T, Right_T, bool> ( \
            dynamic_cast<ETLeaf<Left_T>*>(op->lchild)->m_value, \
            dynamic_cast<ETLeaf<Right_T>*>(op->rchild)->m_value, \
            op->opType \
            ); \
        if (evaluatedValue.first) \
        { \
            returnVal = new ETLeaf<bool>( \
                literalTypeMap<decltype(evaluatedValue.second)>::value, \
                evaluatedValue.second \
                ); \
        } \
    } \
    /* All other operations will return std::common_type between the types. */\
    else \
    { \
        auto evaluatedValue = _evaluateOp<Left_T, Right_T> ( \
            dynamic_cast<ETLeaf<Left_T>*>(op->lchild)->m_value, \
            dynamic_cast<ETLeaf<Right_T>*>(op->rchild)->m_value, \
            op->opType \
            ); \
        if (evaluatedValue.first) \
        { \
            returnVal = new ETLeaf<decltype(evaluatedValue.second)>( \
                literalTypeMap<decltype(evaluatedValue.second)>::value, \
                evaluatedValue.second \
                ); \
        } \
    } \
}
// Generates an error message for invalid operations.
#define INVALID_OPERATION \
std::cout << "Hot Constants:  _evalAndPopETOperator() called on an " \
    "ETOperator with invalid children.  Left: " << size_t(op->lchild->litType) << \
    ", Right: " << size_t(op->rchild->litType) << std::endl;
ETNode* _evalAndPopETOperator(ETOperator* op)
{
    ETNode* returnVal;
    returnVal = nullptr;

    switch (op->lchild->litType)
    {
    case literalType::lit_int:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(int, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(int, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(int, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(int, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(int, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(int, unsigned long long);
            break;

        case literalType::lit_double:
            VALID_OPERATION(int, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(int, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(int, long double);
            break;

        case literalType::lit_bool:
            VALID_OPERATION(int, bool);
            break;

        case literalType::lit_char:
            VALID_OPERATION(int, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(int, char); // TODO: change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(int, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(int, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(int, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_long:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(long, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(long, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(long, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(long, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(long, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(long, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(long, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(long, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(long, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(long, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(long, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(long, char); //TODO: change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(long, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(long, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(long, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_longlong:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(long long, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(long long, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(long long, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(long long, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(long long, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(long long, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(long long, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(long long, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(long long, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(long long, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(long long, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(long long, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(long long, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(long long, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(long long, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_uint:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(unsigned int, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(unsigned int, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(unsigned int, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(unsigned int, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(unsigned int, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(unsigned int, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(unsigned int, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(unsigned int, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(unsigned int, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(unsigned int, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(unsigned int, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(unsigned int, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(unsigned int, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(unsigned int, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(unsigned int, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_ulong:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(unsigned long, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(unsigned long, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(unsigned long, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(unsigned long, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(unsigned long, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(unsigned long, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(unsigned long, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(unsigned long, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(unsigned long, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(unsigned long, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(unsigned long, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(unsigned long, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(unsigned long, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(unsigned long, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(unsigned long, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_ulonglong:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(unsigned long long, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(unsigned long long, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(unsigned long long, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(unsigned long long, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(unsigned long long, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(unsigned long long, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(unsigned long long, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(unsigned long long, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(unsigned long long, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(unsigned long long, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(unsigned long long, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(unsigned long long, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(unsigned long long, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(unsigned long long, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(unsigned long long, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_double:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(double, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(double, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(double, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(double, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(double, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(double, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(double, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(double, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(double, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(double, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(double, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(double, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(double, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(double, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(double, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_float:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(float, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(float, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(float, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(float, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(float, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(float, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(float, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(float, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(float, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(float, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(float, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(float, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(float, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(float, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(float, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_longdouble:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(long double, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(long double, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(long double, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(long double, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(long double, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(long double, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(long double, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(long double, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(long double, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(long double, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(long double, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(long double, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(long double, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(long double, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(long double, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_bool:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(bool, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(bool, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(bool, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(bool, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(bool, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(bool, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(bool, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(bool, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(bool, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(bool, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(bool, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(bool, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(bool, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(bool, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(bool, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_char:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(char, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(char, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(char, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(char, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(char, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(char, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(char, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(char, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(char, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(char, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(char, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(char, char); //TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(char, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(char, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(char, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_char8: //c++17
    {
        switch (op->rchild->litType) // TODO: Change all the LHS to char8_t in c++20
        {
        case literalType::lit_int:
            VALID_OPERATION(char, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(char, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(char, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(char, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(char, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(char, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(char, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(char, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(char, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(char, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(char, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(char, char); //TODO: Change RHS to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(char, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(char, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(char, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_char16:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(char16_t, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(char16_t, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(char16_t, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(char16_t, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(char16_t, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(char16_t, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(char16_t, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(char16_t, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(char16_t, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(char16_t, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(char16_t, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(char16_t, char); // TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(char16_t, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(char16_t, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(char16_t, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_char32:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(char32_t, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(char32_t, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(char32_t, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(char32_t, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(char32_t, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(char32_t, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(char32_t, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(char32_t, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(char32_t, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(char32_t, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(char32_t, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(char32_t, char); // TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(char32_t, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(char32_t, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(char32_t, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    case literalType::lit_wchar:
    {
        switch (op->rchild->litType)
        {
        case literalType::lit_int:
            VALID_OPERATION(wchar_t, int);
            break;
        case literalType::lit_long:
            VALID_OPERATION(wchar_t, long);
            break;
        case literalType::lit_longlong:
            VALID_OPERATION(wchar_t, long long);
            break;
        case literalType::lit_uint:
            VALID_OPERATION(wchar_t, unsigned int);
            break;
        case literalType::lit_ulong:
            VALID_OPERATION(wchar_t, unsigned long);
            break;
        case literalType::lit_ulonglong:
            VALID_OPERATION(wchar_t, unsigned long long);
            break;
        case literalType::lit_double:
            VALID_OPERATION(wchar_t, double);
            break;
        case literalType::lit_float:
            VALID_OPERATION(wchar_t, float);
            break;
        case literalType::lit_longdouble:
            VALID_OPERATION(wchar_t, long double);
            break;
        case literalType::lit_bool:
            VALID_OPERATION(wchar_t, bool);
            break;
        case literalType::lit_char:
            VALID_OPERATION(wchar_t, char);
            break;
        case literalType::lit_char8: //c++17
            VALID_OPERATION(wchar_t, char); // TODO: Change to char8_t in c++20
            break;
        case literalType::lit_char16:
            VALID_OPERATION(wchar_t, char16_t);
            break;
        case literalType::lit_char32:
            VALID_OPERATION(wchar_t, char32_t);
            break;
        case literalType::lit_wchar:
            VALID_OPERATION(wchar_t, wchar_t);
            break;
        default:
            INVALID_OPERATION;
            break;
        }
        break;
    }
    default:
        INVALID_OPERATION;
        break;
    }

    _popETNode(op);
    return returnVal;
}


// Helper macro that applies a unary operation to an ETLeaf.
#define VALID_UNARY_OPERATION(In_T) \
{ \
    /* Logical Not (!) returns bool type. */\
	if (op == unaryOperationType::logical_NOT) \
	{ \
		auto evaluatedValue = _evaluateUnaryOp<In_T, bool>( \
			dynamic_cast<ETLeaf<In_T>*>(leaf)->m_value, op); \
		if (evaluatedValue.first) \
		{ \
			returnVal = new ETLeaf<decltype(evaluatedValue.second)>( \
				literalTypeMap<decltype(evaluatedValue.second)>::value, \
				evaluatedValue.second); \
		} \
	} \
	else \
	{ \
    /* Everything else returns std::common_type. */\
		auto evaluatedValue = _evaluateUnaryOp<In_T>( \
			dynamic_cast<ETLeaf<In_T>*>(leaf)->m_value, op); \
		if (evaluatedValue.first) \
		{ \
			returnVal = new ETLeaf<decltype(evaluatedValue.second)>( \
				literalTypeMap<decltype(evaluatedValue.second)>::value, \
				evaluatedValue.second); \
		} \
	} \
}
ETNode* _applyUnaryOpAndPopETLeaf(ETNode* leaf, unaryOperationType op)
{
    ETNode* returnVal;
    returnVal = nullptr;

	switch (leaf->litType)
	{
	case literalType::lit_int:
		VALID_UNARY_OPERATION(int);
		break;
	case literalType::lit_long:
		VALID_UNARY_OPERATION(long);
		break;
	case literalType::lit_longlong:
		VALID_UNARY_OPERATION(long long);
		break;
	case literalType::lit_uint:
		VALID_UNARY_OPERATION(unsigned int);
		break;
	case literalType::lit_ulong:
		VALID_UNARY_OPERATION(unsigned long);
		break;
	case literalType::lit_ulonglong:
		VALID_UNARY_OPERATION(unsigned long long);
		break;
	case literalType::lit_double:
		VALID_UNARY_OPERATION(double);
		break;
	case literalType::lit_float:
		VALID_UNARY_OPERATION(float);
		break;
	case literalType::lit_longdouble:
		VALID_UNARY_OPERATION(long double);
		break;
	case literalType::lit_char:
		VALID_UNARY_OPERATION(char);
		break;
    case literalType::lit_char8: //c++17
        VALID_UNARY_OPERATION(char); // TODO: Change to char8_t in c++20
        break;
	case literalType::lit_char16:
		VALID_UNARY_OPERATION(char16_t);
		break;
	case literalType::lit_char32:
		VALID_UNARY_OPERATION(char32_t);
		break;
	case literalType::lit_wchar:
		VALID_UNARY_OPERATION(wchar_t);
		break;
	case literalType::lit_bool:
		VALID_UNARY_OPERATION(bool);
        break;
    case literalType::none:
		std::cout << "Hot Constants:  applyUnaryOperatorAndPopNode() called on "
			"an invalid ETLeaf type.  Type: " << size_t(leaf->litType) << std::endl;
		break;
	}

    delete leaf;
    return returnVal;
}


// Expression Evaluation Stuff =========================================================================================


void _tokenizeArithmeticExpr(std::string& expr)
{
    size_t previousPos = 0, currentPos = 0;

    // Look for operators
    do
    {
        currentPos = expr.find_first_of("()~*/%+-^!<>&|", previousPos);
        if (currentPos != std::string::npos)
        {
            if (currentPos > 0)
            {
                // There's a character before currentPos.
                // Insert space before current if previous char isn't already a space,
                // and only if current isn't the minus sign of a floating point exponent.
                if (expr.at(currentPos - 1) != ' ' &&
                    !(expr.at(currentPos) == '-' &&
                      (expr.at(currentPos - 1) == 'e' || expr.at(currentPos - 1) == 'E' ||
                       expr.at(currentPos - 1) == 'p' || expr.at(currentPos - 1) == 'P'))
                    )
                {
                    expr.insert(currentPos, " ");
                    currentPos++;
                }
            }

            if (currentPos + 1 < expr.length())
            {
                // There's a character after current.

                if (currentPos > 0)
                {
                    // There's a character both before and after current.

                    // Insert space after the operator at currentPos if next char isn't already a space,
                    // and only if currentPos isn't the minus sign of a floating point exponent.
                    if (!(expr.at(currentPos) == '-' &&
                          (expr.at(currentPos - 1) == 'e' || expr.at(currentPos - 1) == 'E' ||
                           expr.at(currentPos - 1) == 'p' || expr.at(currentPos - 1) == 'P')))
                    {
                        if (expr.at(currentPos + 1) != ' ')
                        {
                            // currentPos points to an operator followed by a non-space character.
                            // Check for multi-char operators then insert a space after operator.

                            switch (expr.at(currentPos))
                            {
                            case '!':
                                if (expr.at(currentPos + 1) == '=') // !=
                                    currentPos++;
                                break;
                            case '|':
                                if (expr.at(currentPos + 1) == '|') // ||
                                    currentPos++;
                                break;
                            case '&':
                                if (expr.at(currentPos + 1) == '&') // &&
                                    currentPos++;
                                break;
                            case '>':
                                if (expr.at(currentPos + 1) == '>') // >>
                                    currentPos++;
                                else if (expr.at(currentPos + 1) == '=') // >=
                                    currentPos++;
                                break;
                            case '<':
                                if (expr.at(currentPos + 1) == '<') // <<
                                    currentPos++;
                                else if (expr.at(currentPos + 1) == '=')
                                {
                                    if (currentPos + 2 < expr.length())
                                    {
                                        if (expr.at(currentPos + 2) == '>') // <=> (c++20)
                                            currentPos += 2;
                                        else // <=
                                            currentPos++;
                                    }
                                    else // <=
                                        currentPos++;
                                }
                                break;
                            }

                            if (expr.at(currentPos + 1) != ' ')
                                expr.insert(currentPos + 1, " ");
                        }
                    }
                }
                else
                {
                    // currentPos has no precedng characters, so it can only be (, ), ~, +, or -
                    // (the unary operators or parentheses) if the expression is valid.
                    // We assume it is and catch bad tokens later.
                    if (expr.at(currentPos + 1) != ' ')
                        expr.insert(currentPos + 1, " ");
                }
            }

            currentPos++;
            previousPos = currentPos;
        }
    } while (currentPos < expr.length());
}


}
