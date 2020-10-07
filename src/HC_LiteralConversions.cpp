#include "HC_PCH.h"
#include "HC_LiteralConversions.h"

namespace HotConsts
{

// Helper function that identifies floating point type from assumed floating point literal.
literalType IdentifyFloatLiteralType(std::string& token)
{
    char suffix = token.at(token.length() - 1);
    if (suffix == 'f' || suffix == 'F')
        return literalType::lit_float;
    else if (suffix == 'l' || suffix == 'L')
        return literalType::lit_longdouble;
    else
        return literalType::lit_double;
}

// Helper function that identifies integer type from assumed integer literal.
literalType IdentifyIntLiteralType(std::string& token)
{
    if (token.find("LL") != std::string::npos || token.find("ll") != std::string::npos)
    {
        if (token.find_first_of("uU") != std::string::npos)
            return literalType::lit_ulonglong;
        else
            return literalType::lit_longlong;
    }
    else if (token.find_first_of("lL") != std::string::npos)
    {
        if (token.find_first_of("uU") != std::string::npos)
            return literalType::lit_ulong;
        else
            return literalType::lit_long;
    }
    else
    {
        if (token.find_first_of("uU") != std::string::npos)
            return literalType::lit_uint;
        else
            return literalType::lit_int;
    }
}

std::pair<literalType, literalBase> _identifyArithmeticLiteral(std::string& token)
{
    auto returnVal = std::pair<literalType, literalBase>();
    
    if (token.length() > 1)
    {
        if (token.at(0) == '\'')                         // char
        {
            returnVal.first  = literalType::lit_char;
            returnVal.second = literalBase::notapplicable;
        }
        else if (token == "true" || token == "false")     // bool
        {
            returnVal.first  = literalType::lit_bool;
            returnVal.second = literalBase::notapplicable;
        }
        else
        {
            char workingChar = token.at(1);
            
            if (workingChar == '\'')
            {
                returnVal.second = literalBase::notapplicable;
                
                workingChar = token.at(0);
                if (workingChar == 'u')
                    returnVal.first = literalType::lit_char16;     // char16_t
                else if (workingChar == 'U')
                    returnVal.first = literalType::lit_char32;     // char32_t
                else if (workingChar == 'L')
                    returnVal.first = literalType::lit_wchar;      // wchar_t
                else
                    returnVal.first =literalType::none;
            }
            //else if (workingChar == '8' && token.at(0) == 'u')     // char8_t (c++20)
            //{
            //    // chars with u8 prefix
            //    returnVal.second = literalBase::notapplicable;
            //    returnVal.first =literalType::lit_char;
            //}
            else if (workingChar == 'b' || workingChar == 'B')      // binary integer
            {
                // c++ doesn't support binary float literals
                returnVal.first  = IdentifyIntLiteralType(token);
                returnVal.second = literalBase::binary;
            }
            else if (workingChar == 'x' || workingChar == 'X')
            {
                returnVal.second = literalBase::hex;
                
                if (token.find_first_of("pP") != std::string::npos)      // hex float
                    returnVal.first = IdentifyFloatLiteralType(token);
                else
                    returnVal.first = IdentifyIntLiteralType(token);     // hex int
            }
            else
            {
                if (token.find_first_of(".eE") != std::string::npos)
                {
                    returnVal.first  = IdentifyFloatLiteralType(token);   // decimal float
                    returnVal.second = literalBase::decimal;
                }
                else if (token.at(0) == '0')
                {
                    returnVal.first  = IdentifyIntLiteralType(token);     // octal int
                    returnVal.second = literalBase::octal;
                }
                else
                {
                    returnVal.first  = IdentifyIntLiteralType(token);     // decimal int
                    returnVal.second = literalBase::decimal;
                }
            }
        }
    }
    else
    {
        // A single character can only be a regular int.
        returnVal.first  = literalType::lit_int;
        returnVal.second = literalBase::decimal;                           // trivial int
    }
    
    return returnVal;
}

operationType _identifyOperator(std::string& token)
{
    switch (token.at(0))
    {
    case '*':
        return token.length() == 1 ? operationType::multiply : operationType::none;
        break;
    case '/':
        return token.length() == 1 ? operationType::divide : operationType::none;
        break;
    case '%':
        return token.length() == 1 ? operationType::modulo : operationType::none;
        break;
    case '+':
        return token.length() == 1 ? operationType::add : operationType::none;
        break;
    case '-':
        return token.length() == 1 ? operationType::subtract : operationType::none;
        break;
    case '^':
        return token.length() == 1 ? operationType::bitwise_XOR : operationType::none;
        break;
    case '=': // Looking for '=='
        return token.length() == 2 ? operationType::compare_eq : operationType::none;
        break;
    case '!': // Looking for '!='
        return token.length() == 2 ? operationType::compare_neq : operationType::none;
        break;
    case '<':
        if (token.length() > 1)
        {
            if (token.at(1) == '<')
                return operationType::bitshift_left;
            else if (token.at(1) == '=')
            {
                if (token.length() == 2)
                    return operationType::compare_ltoreq;
                //else
                //    return operationType::compare_threeway; //c++20
            }
        }
        else
            return operationType::compare_lt;
        break;
    case '>':
        if (token.length() > 1)
        {
            if (token.at(1) == '>')
                return operationType::bitshift_right;
            else if (token.at(1) == '=')
                return operationType::compare_gtoreq;
        }
        else
            return operationType::compare_gt;
        break;
    case '&':
        if (token.length() > 1)
            return operationType::logical_AND;
        else
            return operationType::bitwise_AND;
        break;
    case '|':
        if (token.length() > 1)
            return operationType::logical_OR;
        else
            return operationType::bitwise_OR;
        break;
    default:
        return operationType::none;
        break;
    }
    
    return operationType::none;
}

unaryOperationType _identifyUnaryOperator(std::string& token)
{
    if (token.length() == 1)
    {
        switch (token.at(0))
        {
        case '+':
            return unaryOperationType::unary_plus;
            break;
        case '-':
            return unaryOperationType::unary_minus;
            break;
        case '!':
            return unaryOperationType::logical_NOT;
            break;
        case '~':
            return unaryOperationType::bitwise_NOT;
            break;
        default:
            return unaryOperationType::none;
            break;
        }
    }
    else
        return unaryOperationType::none;
}


// Conversion code =====================================================================================================


// Integer conversions

int _convertLiteralTo_int(std::string& token, literalBase base)
{
    int returnVal = 0;
    size_t postLiteralPos = 0;

    switch (base)
    {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoi.
            token.erase(0, 2);
            returnVal = stoi(token, &postLiteralPos, 2);
            break;
        default:
            // stoi already handles decimal, hex, and oct.
            returnVal = stoi(token, &postLiteralPos, 0);
            break;
    }
    
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");

    return returnVal;
}

long _convertLiteralTo_long(std::string& token, literalBase base)
{
    long returnVal = 0;
    size_t postLiteralPos = 0;

    switch (base)
    {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stol.
            token.erase(0, 2);
            returnVal = stol(token, &postLiteralPos, 2);
            break;
        default:
            // stol already handles decimal, hex, and oct.
            returnVal = stol(token, &postLiteralPos, 0);
            break;
    }
    
    postLiteralPos++; // An "l" or "L" suffix is expected.
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");
    
    return returnVal;
}

long long _convertLiteralTo_longlong(std::string& token, literalBase base)
{
    long long returnVal = 0;
    size_t postLiteralPos = 0;

    switch (base)
    {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoll.
            token.erase(0, 2);
            returnVal = stoll(token, &postLiteralPos, 2);
            break;
        default:
            // stoll already handles decimal, hex, and oct.
            returnVal = stoll(token, &postLiteralPos, 0);
            break;
    }

    postLiteralPos += 2; // An "ll" or "LL" suffix is expected.
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");
    
    return returnVal;
}

unsigned int _convertLiteralTo_uint(std::string& token, literalBase base)
{
    unsigned long returnVal = 0;
    size_t postLiteralPos = 0;

    switch (base)
    {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoul.
            token.erase(0, 2);
            returnVal = stoul(token, &postLiteralPos, 2); //TODO: Handle out of range inputs!
            break;
        default:
            // stoul already handles decimal, hex, and oct.
            returnVal = stoul(token, &postLiteralPos, 0);
            break;
    }

    if (returnVal > UINT_MAX)
    {
        throw std::out_of_range("Hot Consts:  An unsigned int literal was out of range.");
    }

    postLiteralPos++; // A "u" or "U" suffix is expected.
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");
    
    return returnVal;
}

unsigned long _convertLiteralTo_ulong(std::string& token, literalBase base)
{
    unsigned long returnVal = 0;
    size_t postLiteralPos = 0;

    switch (base)
    {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoul.
            token.erase(0, 2);
            returnVal = stoul(token, &postLiteralPos, 2);
            break;
        default:
            // stoul already handles decimal, hex, and oct.
            returnVal = stoul(token, &postLiteralPos, 0);
            break;
    }
    
    postLiteralPos += 2; // A "ul" or "UL" suffix is expected.
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");
    
    return returnVal;
}

unsigned long long _convertLiteralTo_ulonglong(std::string& token, literalBase base)
{
    unsigned long long returnVal = 0;
    size_t postLiteralPos = 0;

    switch (base)
    {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoull.
            token.erase(0, 2);
            returnVal = stoull(token, &postLiteralPos, 2);
            break;
        default:
            // stoull already handles decimal, hex, and oct.
            returnVal = stoull(token, &postLiteralPos, 0);
            break;
    }
    
    postLiteralPos += 3; // A "ull" or "ULL" suffix is expected.
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");
    
    return returnVal;
}

// Floating point conversions

double _convertLiteralTo_double(std::string& token, literalBase base)
{
    double returnVal = 0;
    size_t postLiteralPos = 0;

    returnVal = stod(token, &postLiteralPos);

    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");
    
    return returnVal;
}

float _convertLiteralTo_float(std::string& token, literalBase base)
{
    float returnVal = 0;
    size_t postLiteralPos = 0;

    returnVal = stof(token, &postLiteralPos);

    postLiteralPos++; // An "f" or "F" suffix is expected.
    
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");
    
    return returnVal;
}

long double _convertLiteralTo_longdouble(std::string& token, literalBase base)
{
    long double returnVal = 0;
    size_t postLiteralPos = 0;

    returnVal = stold(token, &postLiteralPos);

    postLiteralPos++; // An "l" or "L" suffix is expected.
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Consts:  The literal has an invalid suffix.");
    
    return returnVal;
}

// Char conversions
// TODO: actually implement these

char _convertLiteralTo_char(std::string& token)
{
    return '0';
}

char16_t _convertLiteralTo_char16(std::string& token)
{
    return '0';
}

char32_t _convertLiteralTo_char32(std::string& token)
{
    return '0';
}

wchar_t _convertLiteralTo_wchar(std::string& token)
{
    return '0';
}

int convertLiteralTo_multichar(std::string& token)
{
    return '0';
}

// Bool conversion

bool _convertLiteralTo_bool(std::string& token)
{
    if (token == "true")
        return true;
    else if (token == "false")
        return false;
    else
        throw std::invalid_argument("Hot Constants:  _convertLiteralTo_bool() was called with an invalid token.");
}


// String conversions
// TODO: define string conversion functions

}
