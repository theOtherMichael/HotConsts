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

std::pair<bool, int> _convertLiteralTo_int(std::string& token, literalBase base)
{
    std::pair<bool, int> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        switch (base)
        {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoi.
            token.erase(0, 2);
            returnVal.second = stoi(token, &postLiteralPos, 2);
            break;
        default:
            // stoi already handles decimal, hex, and oct.
            returnVal.second = stoi(token, &postLiteralPos, 0);
            break;
        }

        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
	{
		std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
            "\" is too large for type 'int'." << std::endl;
        returnVal.first = false;
	}
	catch (std::invalid_argument& e)
	{
        returnVal.first = false;
	}

    return returnVal;
}

std::pair<bool, long> _convertLiteralTo_long(std::string& token, literalBase base)
{
    std::pair<bool, long> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        switch (base)
        {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stol.
            token.erase(0, 2);
            returnVal.second = stol(token, &postLiteralPos, 2);
            break;
        default:
            // stol already handles decimal, hex, and oct.
            returnVal.second = stol(token, &postLiteralPos, 0);
            break;
        }

        postLiteralPos++; // An "l" or "L" suffix is expected.
        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
        "\" is too large for type 'long'." << std::endl;
        returnVal.first = false;
    }
    catch (std::invalid_argument& e)
    {
        returnVal.first = false;
    }

    return returnVal;
}

std::pair<bool, long long> _convertLiteralTo_longlong(std::string& token, literalBase base)
{
    std::pair<bool, long long> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        switch (base)
        {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoll.
            token.erase(0, 2);
            returnVal.second = stoll(token, &postLiteralPos, 2);
            break;
        default:
            // stoll already handles decimal, hex, and oct.
            returnVal.second = stoll(token, &postLiteralPos, 0);
            break;
        }

        postLiteralPos += 2; // An "ll" or "LL" suffix is expected.
        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
        "\" is too large for type 'long long'." << std::endl;
        returnVal.first = false;
    }
    catch (std::invalid_argument& e)
    {
        returnVal.first = false;
    }

    return returnVal;
}

std::pair<bool, unsigned int> _convertLiteralTo_uint(std::string& token, literalBase base)
{
    std::pair<bool, unsigned int> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        switch (base)
        {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoul.
            token.erase(0, 2);
            returnVal.second = stoul(token, &postLiteralPos, 2); //TODO: Handle out of range inputs!
            break;
        default:
            // stoul already handles decimal, hex, and oct.
            returnVal.second = stoul(token, &postLiteralPos, 0);
            break;
        }

        postLiteralPos++; // A "u" or "U" suffix is expected.
        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
        "\" is too large for type 'unsigned int'." << std::endl;
        returnVal.first = false;
    }
    catch (std::invalid_argument& e)
    {
        returnVal.first = false;
    }

    return returnVal;
}

std::pair<bool, unsigned long> _convertLiteralTo_ulong(std::string& token, literalBase base)
{
    std::pair<bool, unsigned long> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        switch (base)
        {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoul.
            token.erase(0, 2);
            returnVal.second = stoul(token, &postLiteralPos, 2);
            break;
        default:
            // stoul already handles decimal, hex, and oct.
            returnVal.second = stoul(token, &postLiteralPos, 0);
            break;
        }

        postLiteralPos += 2; // A "ul" or "UL" suffix is expected.
        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
        "\" is too large for type 'unsigned long'." << std::endl;
        returnVal.first = false;
    }
    catch (std::invalid_argument& e)
    {
        returnVal.first = false;
    }

    return returnVal;
}

std::pair<bool, unsigned long long> _convertLiteralTo_ulonglong(std::string& token, literalBase base)
{
    std::pair<bool, unsigned long long> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        switch (base)
        {
        case literalBase::binary:
            // 0b or 0B prefix.  This is not handled in stoull.
            token.erase(0, 2);
            returnVal.second = stoull(token, &postLiteralPos, 2);
            break;
        default:
            // stoull already handles decimal, hex, and oct.
            returnVal.second = stoull(token, &postLiteralPos, 0);
            break;
        }

        postLiteralPos += 3; // A "ull" or "ULL" suffix is expected.
        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
        "\" is too large for type 'unsigned long long'." << std::endl;
        returnVal.first = false;
    }
    catch (std::invalid_argument& e)
    {
        returnVal.first = false;
    }

    return returnVal;
}

// Floating point conversions

std::pair<bool, double> _convertLiteralTo_double(std::string& token, literalBase base)
{
    std::pair<bool, double> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        returnVal.second = stod(token, &postLiteralPos);

        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
        "\" is too large for type 'double'." << std::endl;
        returnVal.first = false;
    }
    catch (std::invalid_argument& e)
    {
        returnVal.first = false;
    }

    return returnVal;
}

std::pair<bool, float> _convertLiteralTo_float(std::string& token, literalBase base)
{
    std::pair<bool, float> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        returnVal.second = stof(token, &postLiteralPos);

        postLiteralPos++; // An "f" or "F" suffix is expected.
        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
        "\" is too large for type 'float'." << std::endl;
        returnVal.first = false;
    }
    catch (std::invalid_argument& e)
    {
        returnVal.first = false;
    }

    return returnVal;
}

std::pair<bool, long double> _convertLiteralTo_longdouble(std::string& token, literalBase base)
{
    std::pair<bool, long double> returnVal = {true, 0};
    size_t postLiteralPos = 0;

    try
    {
        returnVal.second = stold(token, &postLiteralPos);

        postLiteralPos++; // An "l" or "L" suffix is expected.
        if (postLiteralPos < token.length())
        {
            // The literal has unexpected characters following it, making it invalid.
            returnVal.first = false;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Hot Constants:  Conversion failure: Literal value \"" << token <<
        "\" is too large for type 'long double'." << std::endl;
        returnVal.first = false;
    }
    catch (std::invalid_argument& e)
    {
        returnVal.first = false;
    }

    return returnVal;
}

// Char conversions
// TODO: actually implement these

std::pair<bool, char> _convertLiteralTo_char(std::string& token)
{
    return std::pair(false, '0');
}

std::pair<bool, char16_t> _convertLiteralTo_char16(std::string& token)
{
    return std::pair(false, '0');
}

std::pair<bool, char32_t> _convertLiteralTo_char32(std::string& token)
{
    return std::pair(false, '0');
}

std::pair<bool, wchar_t> _convertLiteralTo_wchar(std::string& token)
{
    return std::pair(false, '0');
}

std::pair<bool, int> convertLiteralTo_multichar(std::string& token)
{
    return std::pair(false, '0');
}

// Bool conversion

std::pair<bool, bool> _convertLiteralTo_bool(std::string& token)
{
    if (token == "true")
        return std::pair(true, true);
    else if (token == "false")
        return std::pair(true, false);
    else
    {
        return std::pair(false, false);
    }
}


// String conversions
// TODO: define string conversion functions

}
