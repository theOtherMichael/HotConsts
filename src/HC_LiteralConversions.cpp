#include "HC_PCH.h"
#include "HC_LiteralConversions.h"

#define RANGEOFTYPE(type) ((1ull << sizeof( type ) * CHAR_BIT) - 1)

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
            else if (workingChar == '8' && token.at(0) == 'u')     // char8_t (c++17)
            {
                returnVal.second = literalBase::notapplicable;
                returnVal.first =literalType::lit_char8;
            }
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
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");

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
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");
    
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
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");
    
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
            returnVal = stoul(token, &postLiteralPos, 2);
            break;
        default:
            // stoul already handles decimal, hex, and oct.
            returnVal = stoul(token, &postLiteralPos, 0);
            break;
    }

    // Because there's no "stou" in the standard library, we must "fake" out of range conversions here.
    if (returnVal > UINT_MAX)
    {
        throw std::out_of_range("Hot Constants:  An 'unsigned int' literal was out of range.");
    }

    postLiteralPos++; // A "u" or "U" suffix is expected.
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");
    
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
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");
    
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
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");
    
    return returnVal;
}

// Floating point conversions

double _convertLiteralTo_double(std::string& token, literalBase base)
{
    double returnVal = 0;
    size_t postLiteralPos = 0;

    returnVal = stod(token, &postLiteralPos);

    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");
    
    return returnVal;
}

float _convertLiteralTo_float(std::string& token, literalBase base)
{
    float returnVal = 0;
    size_t postLiteralPos = 0;

    returnVal = stof(token, &postLiteralPos);

    postLiteralPos++; // An "f" or "F" suffix is expected.
    
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");
    
    return returnVal;
}

long double _convertLiteralTo_longdouble(std::string& token, literalBase base)
{
    long double returnVal = 0;
    size_t postLiteralPos = 0;

    returnVal = stold(token, &postLiteralPos);

    postLiteralPos++; // An "l" or "L" suffix is expected.
    if (postLiteralPos < token.length())
        throw std::invalid_argument("Hot Constants:  The literal has an invalid suffix.");
    
    return returnVal;
}

// Char conversions

char _convertLiteralTo_char(std::string& token)
{
    if (token.length() == 1)
    {
        throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
        return '\0';
    }
    else if (token.at(1) == '\\')
    {
        // Escape sequence
        switch (token.at(2))
        {
            case '\'':
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\'';
                break;
            case '\"':
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\"';
                break;
            case '\?':
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\?';
                break;
            case '\\':
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\\';
                break;
            case 'a': // audible bell
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\a';
                break;
            case 'b': // backspace
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\b';
                break;
            case 'f': // form feed
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\f';
                break;
            case 'n': // line feed
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\n';
                break;
            case 'r': // carriage return
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\r';
                break;
            case 't': // horizontal tab
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\t';
                break;
            case 'v': // vertical tab
                if (token.length() > 4)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                return '\v';
                break;
            case 'x': // arbitrary hex value
            {
                std::string val = token.substr(3, token.length() - 4);
                size_t postpos;
                long converted = std::stol(val, &postpos, 16);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                if (converted > RANGEOFTYPE(char))
                    throw std::out_of_range("Hot Constants:  Hex escape sequence out of range.");
                return converted;
            }
                break;
            case 'u': // universal character name (4 digits)
            {
                if (token.length() != 8)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                std::string val = token.substr(3, 4);
                return (char)std::stoi(val, nullptr, 16);
            }
                break;
            case 'U': // universal character name (8 digits)
            {
                if (token.length() != 12)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                std::string val = token.substr(3, 8);
                return (char)std::stoi(val, nullptr, 16);
            }
                break;
            default: // arbitrary octal value
            {
                std::string val = token.substr(2, token.length() - 3);
                size_t postpos;
                long converted = std::stol(val, &postpos, 8);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
                if (converted > 0377)
                    throw std::out_of_range("Hot Constants:  Octal escape sequence out of range.");
                return converted;
            }
                break;
        }
    }
    else
    {
        // Confirm there's enough characters.
        if (token.length() == 3)
        {
            return token.at(1);
        }
        else
        {
            throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char() was passed an invalid literal.");
            return '\0';
        }
    }
}

char _convertLiteralTo_char8(std::string& token) // C++17 TODO: change this to char8_t in c++20
{
    if (token.length() == 3)
    {
        throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
        return '\0';
    }
    else if (token.at(3) == '\\')
    {
        // Escape sequence
        switch (token.at(4))
        {
            case '\'':
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\'';
                break;
            case '\"':
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\"';
                break;
            case '\?':
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\?';
                break;
            case '\\':
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\\';
                break;
            case 'a': // audible bell
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\a';
                break;
            case 'b': // backspace
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\b';
                break;
            case 'f': // form feed
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\f';
                break;
            case 'n': // line feed
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\n';
                break;
            case 'r': // carriage return
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\r';
                break;
            case 't': // horizontal tab
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\t';
                break;
            case 'v': // vertical tab
                if (token.length() > 6)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                return u8'\v';
                break;
            case 'x': // arbitrary hex value
            {
                std::string val = token.substr(5, token.length() - 6);
                size_t postpos;
                long converted = std::stol(val, &postpos, 16);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                if (converted > 0x7F) // Largest valid UTF-8 literal
                    throw std::out_of_range("Hot Constants:  Hex escape sequence out of range.");
                return converted;
            }
                break;
            case 'u': // universal character name (4 digits)
            {
                if (token.length() != 10)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                std::string val = token.substr(5, 4);
                return (char)std::stoi(val, nullptr, 16);
            }
                break;
            case 'U': // universal character name (8 digits)
            {
                if (token.length() != 14)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                std::string val = token.substr(5, 8);
                return (char)std::stoi(val, nullptr, 16);
            }
                break;
            default: // arbitrary octal value
            {
                std::string val = token.substr(4, token.length() - 5);
                size_t postpos;
                long converted = std::stol(val, &postpos, 8);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
                if (converted > 0177)
                    throw std::out_of_range("Hot Constants:  Octal escape sequence out of range.");
                return converted;
            }
                break;
        }
    }
    else
    {
        // Confirm there's enough characters.
        if (token.length() == 5)
        {
            return token.at(3);
        }
        else
        {
            throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char8() was passed an invalid literal.");
            return '\0';
        }
    }
}

char16_t _convertLiteralTo_char16(std::string& token)
{
    if (token.length() == 2)
    {
        throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
        return '\0';
    }
    else if (token.at(2) == '\\')
    {
        // Escape sequence
        switch (token.at(3))
        {
            case '\'':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\'';
                break;
            case '\"':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\"';
                break;
            case '\?':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\?';
                break;
            case '\\':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\\';
                break;
            case 'a': // audible bell
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\a';
                break;
            case 'b': // backspace
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\b';
                break;
            case 'f': // form feed
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\f';
                break;
            case 'n': // line feed
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\n';
                break;
            case 'r': // carriage return
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\r';
                break;
            case 't': // horizontal tab
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\t';
                break;
            case 'v': // vertical tab
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                return u'\v';
                break;
            case 'x': // arbitrary hex value
            {
                std::string val = token.substr(4, token.length() - 5);
                size_t postpos;
                long converted = std::stol(val, &postpos, 16);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                if (converted > 0xFFFF) // Largest valid UTF-16 literal
                    throw std::out_of_range("Hot Constants:  Hex escape sequence out of range.");
                return converted;
            }
                break;
            case 'u': // universal character name (4 digits)
            {
                if (token.length() != 9)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                std::string val = token.substr(4, 4);
                return (char16_t)std::stoi(val, nullptr, 16);
            }
                break;
            case 'U': // universal character name (8 digits)
            {
                if (token.length() != 13)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                std::string val = token.substr(4, 8);
                return (char16_t)std::stoi(val, nullptr, 16);
            }
                break;
            default: // arbitrary octal value
            {
                std::string val = token.substr(3, token.length() - 4);
                size_t postpos;
                long converted = std::stol(val, &postpos, 8);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
                if (converted > 0777)
                    throw std::out_of_range("Hot Constants:  Octal escape sequence out of range.");
                return converted;
            }
                break;
        }
    }
    else
    {
        // Confirm there's enough characters.
        if (token.length() == 4)
        {
            return token.at(2);
        }
        else
        {
            throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char16() was passed an invalid literal.");
            return '\0';
        }
    }
}

char32_t _convertLiteralTo_char32(std::string& token)
{
    if (token.length() == 2)
    {
        throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
        return '\0';
    }
    else if (token.at(2) == '\\')
    {
        // Escape sequence
        switch (token.at(3))
        {
            case '\'':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\'';
                break;
            case '\"':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\"';
                break;
            case '\?':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\?';
                break;
            case '\\':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\\';
                break;
            case 'a': // audible bell
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\a';
                break;
            case 'b': // backspace
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\b';
                break;
            case 'f': // form feed
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\f';
                break;
            case 'n': // line feed
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\n';
                break;
            case 'r': // carriage return
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\r';
                break;
            case 't': // horizontal tab
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\t';
                break;
            case 'v': // vertical tab
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                return U'\v';
                break;
            case 'x': // arbitrary hex value
            {
                std::string val = token.substr(4, token.length() - 5);
                size_t postpos;
                long converted = std::stol(val, &postpos, 16);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                if (converted > UINT_LEAST32_MAX)
                    throw std::out_of_range("Hot Constants:  Hex escape sequence out of range.");
                return converted;
            }
                break;
            case 'u': // universal character name (4 digits)
            {
                if (token.length() != 9)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                std::string val = token.substr(4, 4);
                return (char32_t)std::stoi(val, nullptr, 16);
            }
                break;
            case 'U': // universal character name (8 digits)
            {
                if (token.length() != 13)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                std::string val = token.substr(4, 8);
                return (char32_t)std::stoi(val, nullptr, 16);
            }
                break;
            default: // arbitrary octal value
            {
                std::string val = token.substr(3, token.length() - 4);
                size_t postpos;
                long converted = std::stol(val, &postpos, 8);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
                if (converted > 0777)
                    throw std::out_of_range("Hot Constants:  Octal escape sequence out of range.");
                return converted;
            }
                break;
        }
    }
    else
    {
        // Confirm there's enough characters.
        if (token.length() == 4)
        {
            return token.at(2);
        }
        else
        {
            throw std::invalid_argument("Hot Constants:  _convertLiteralTo_char32() was passed an invalid literal.");
            return '\0';
        }
    }
}

wchar_t _convertLiteralTo_wchar(std::string& token)
{
    if (token.length() == 2)
    {
        throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
        return '\0';
    }
    else if (token.at(2) == '\\')
    {
        // Escape sequence
        switch (token.at(3))
        {
            case '\'':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\'';
                break;
            case '\"':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\"';
                break;
            case '\?':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\?';
                break;
            case '\\':
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\\';
                break;
            case 'a': // audible bell
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\a';
                break;
            case 'b': // backspace
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\b';
                break;
            case 'f': // form feed
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\f';
                break;
            case 'n': // line feed
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\n';
                break;
            case 'r': // carriage return
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\r';
                break;
            case 't': // horizontal tab
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\t';
                break;
            case 'v': // vertical tab
                if (token.length() > 5)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                return L'\v';
                break;
            case 'x': // arbitrary hex value
            {
                std::string val = token.substr(4, token.length() - 5);
                size_t postpos;
                long converted = std::stol(val, &postpos, 16);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                if (converted > RANGEOFTYPE(wchar_t))
                    throw std::out_of_range("Hot Constants:  Hex escape sequence out of range.");
                return converted;
            }
                break;
            case 'u': // universal character name (4 digits)
            {
                if (token.length() != 9)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                std::string val = token.substr(4, 4);
                return (wchar_t)std::stoi(val, nullptr, 16);
            }
                break;
            case 'U': // universal character name (8 digits)
            {
                if (token.length() != 13)
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                std::string val = token.substr(4, 8);
                return (wchar_t)std::stoi(val, nullptr, 16);
            }
                break;
            default: // arbitrary octal value
            {
                std::string val = token.substr(3, token.length() - 4);
                size_t postpos;
                long converted = std::stol(val, &postpos, 8);
                if (postpos < val.length())
                    throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
                if (converted > 0777)
                    throw std::out_of_range("Hot Constants:  Octal escape sequence out of range.");
                return converted;
            }
                break;
        }
    }
    else
    {
        // Confirm there's enough characters.
        if (token.length() == 4)
        {
            return token.at(2);
        }
        else
        {
            throw std::invalid_argument("Hot Constants:  _convertLiteralTo_wchar() was passed an invalid literal.");
            return '\0';
        }
    }
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


}
