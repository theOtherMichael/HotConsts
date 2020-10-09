#include <HotConsts/HotConsts.h>
#include "_tests.h"
#include "LiteralSamples.h"

#define RANGEOFTYPE(type) ((1ull << sizeof( type ) * CHAR_BIT) - 1)

/*
	Tests conversion of literals into values.
*/


// Good input -----------------------------------------------------------------

bool convertIntLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (intLiterals.size() == intLiteralConversions.size())
        {
            auto conversionIt = intLiteralConversions.begin();
            for (auto literalIt = intLiterals.begin();
                 literalIt != intLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_int(*literalIt, base);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Incorrect literal conversion: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertIntLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertIntLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "intLiterals and intLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertLongLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (longLiterals.size() == longLiteralConversions.size())
        {
            auto conversionIt = longLiteralConversions.begin();
            for (auto literalIt = longLiterals.begin();
                 literalIt != longLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_long(*literalIt, base);
                    
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Incorrect literal conversion: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertLongLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertLongLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "longLiterals and longLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertLongLongLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (longlongLiterals.size() == longlongLiteralConversions.size())
        {
            auto conversionIt = longlongLiteralConversions.begin();
            for (auto literalIt = longlongLiterals.begin();
                 literalIt != longlongLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_longlong(*literalIt, base);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Incorrect literal conversion: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertLongLongLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertLongLongLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "longlongLiterals and longlongLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertUIntLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (uintLiterals.size() == uintLiteralConversions.size())
        {
            auto conversionIt = uintLiteralConversions.begin();
            for (auto literalIt = uintLiterals.begin();
                 literalIt != uintLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_uint(*literalIt, base);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Incorrect literal conversion: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertUIntLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertUIntLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "uintLiterals and uintLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertULongLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (ulongLiterals.size() == ulongLiteralConversions.size())
        {
            auto conversionIt = ulongLiteralConversions.begin();
            for (auto literalIt = ulongLiterals.begin();
                 literalIt != ulongLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_ulong(*literalIt, base);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Incorrect literal conversion: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertULongLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertULongLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "ulongLiterals and ulongLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertULongLongLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (ulonglongLiterals.size() == ulonglongLiteralConversions.size())
        {
            auto conversionIt = ulonglongLiteralConversions.begin();
            for (auto literalIt = ulonglongLiterals.begin();
                 literalIt != ulonglongLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_ulonglong(*literalIt, base);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Incorrect literal conversion: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertULongLongLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertULongLongLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "ulonglongLiterals and ulonglongLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool conversionPromotesIntegers()
{
    bool returnVal = true;
    
    std::string testString = "9223372036854775807";
    HotConsts::ETNode* testLeaf = HotConsts::_newETLeaf(testString);
    if (testLeaf)
    {
        if (testLeaf->litType != HotConsts::literalTypeMap<decltype((9223372036854775807))>::value)
            returnVal = false;
        delete testLeaf;
    }
    else
    {
        returnVal = false;
    }
    
    testString = "18446744073709551615u";
    testLeaf = HotConsts::_newETLeaf(testString);
    if (testLeaf)
    {
        if (testLeaf->litType != HotConsts::literalTypeMap<decltype((18446744073709551615u))>::value)
            returnVal = false;
        delete testLeaf;
    }
    else
    {
        returnVal = false;
    }
    
    return returnVal;
}

bool convertDoubleLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (doubleLiterals.size() == doubleLiteralConversions.size())
        {
            auto conversionIt = doubleLiteralConversions.begin();
            for (auto literalIt = doubleLiterals.begin();
                 literalIt != doubleLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_double(*literalIt, base);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Double literal conversion is incorrect: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertDoubleLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertDoubleLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "doubleLiterals and doubleLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertFloatLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (floatLiterals.size() == floatLiteralConversions.size())
        {
            auto conversionIt = floatLiteralConversions.begin();
            for (auto literalIt = floatLiterals.begin();
                 literalIt != floatLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_float(*literalIt, base);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Float literal conversion is incorrect: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertFloatLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertFloatLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "floatLiterals and floatLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertLongDoubleLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (longDoubleLiterals.size() == longDoubleLiteralConversions.size())
        {
            auto conversionIt = longDoubleLiteralConversions.begin();
            for (auto literalIt = longDoubleLiterals.begin();
                 literalIt != longDoubleLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto base = HotConsts::_identifyArithmeticLiteral(*literalIt).second;
                    auto convertedVal = HotConsts::_convertLiteralTo_longdouble(*literalIt, base);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Long double literal conversion is incorrect: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertLongDoubleLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertLongDoubleLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "longDoubleLiterals and longDoubleLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}

bool convertBoolLiterals()
{
    bool returnVal = true;
    
    std::string testStr = "true";
    {
        try
        {
            bool result = HotConsts::_convertLiteralTo_bool(testStr);
            
            if (!result)
            {
                std::cout << RED << "Bool literal conversion is incorrect: " << YELLOW << "\"" << testStr << "\""
                << RED << " converts to " << result << "." << WHITE << std::endl;
                returnVal = false;
            }
        }
        catch (std::invalid_argument& e)
        {
            std::cout << RED << "Bool literal failed to convert.  Literal: " << YELLOW << "\"" << testStr << "\"." << WHITE << std::endl;
            returnVal = false;
        }
    }
    
    testStr = "false";
    {
        try
        {
            bool result = HotConsts::_convertLiteralTo_bool(testStr);
            
            if (result)
            {
                std::cout << RED << "Bool literal conversion is incorrect: " << YELLOW << "\"" << testStr << "\""
                << RED << " converts to " << result << "." << WHITE << std::endl;
                returnVal = false;
            }
        }
        catch (std::invalid_argument& e)
        {
            std::cout << RED << "Bool literal failed to convert.  Literal: " << YELLOW << "\"" << testStr << "\"." << WHITE << std::endl;
            returnVal = false;
        }
    }
    return returnVal;
}

bool convertCharLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (charLiterals.size() == charLiteralConversions.size())
        {
            auto conversionIt = charLiteralConversions.begin();
            for (auto literalIt = charLiterals.begin();
                 literalIt != charLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto convertedVal = HotConsts::_convertLiteralTo_char(*literalIt);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Char literal conversion is incorrect: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertCharLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertCharLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "charLiterals and charLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertChar8Literals() //c++17
{
    bool returnVal = true;
    
    try
    {
        if (char8Literals.size() == char8LiteralConversions.size())
        {
            auto conversionIt = char8LiteralConversions.begin();
            for (auto literalIt = char8Literals.begin();
                 literalIt != char8Literals.end();
                 ++literalIt)
            {
                try
                {
                    auto convertedVal = HotConsts::_convertLiteralTo_char8(*literalIt);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "UTF-8 char literal conversion is incorrect: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertChar8Literals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertChar8Literals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "char8Literals and char8LiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertChar16Literals()
{
    bool returnVal = true;
    
    try
    {
        if (char16Literals.size() == char16LiteralConversions.size())
        {
            auto conversionIt = char16LiteralConversions.begin();
            for (auto literalIt = char16Literals.begin();
                 literalIt != char16Literals.end();
                 ++literalIt)
            {
                try
                {
                    auto convertedVal = HotConsts::_convertLiteralTo_char16(*literalIt);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "UTF-16 char literal conversion is incorrect: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertChar16Literals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertChar16Literals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "char16Literals and char16LiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertChar32Literals()
{
    bool returnVal = true;
    
    try
    {
        if (char32Literals.size() == char32LiteralConversions.size())
        {
            auto conversionIt = char32LiteralConversions.begin();
            for (auto literalIt = char32Literals.begin();
                 literalIt != char32Literals.end();
                 ++literalIt)
            {
                try
                {
                    auto convertedVal = HotConsts::_convertLiteralTo_char32(*literalIt);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "UTF-32 char literal conversion is incorrect: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertChar32Literals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertChar32Literals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "char32Literals and char32LiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool convertWCharLiterals()
{
    bool returnVal = true;
    
    try
    {
        if (wcharLiterals.size() == wcharLiteralConversions.size())
        {
            auto conversionIt = wcharLiteralConversions.begin();
            for (auto literalIt = wcharLiterals.begin();
                 literalIt != wcharLiterals.end();
                 ++literalIt)
            {
                try
                {
                    auto convertedVal = HotConsts::_convertLiteralTo_wchar(*literalIt);
                    if (convertedVal != *conversionIt)
                    {
                        std::cout << RED << "Wide char literal conversion is incorrect: " << YELLOW << "\"" << *literalIt
                        << "\"" << RED << " converts to " << YELLOW << convertedVal << RED << "." << WHITE << std::endl;
                        returnVal = false;
                    }
                    ++conversionIt;
                }
                catch (std::out_of_range& e)
                {
                    std::cout << RED << "std::out_of_range thrown in test convertWCharLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << RED << "std::invalid_argument thrown in test convertWCharLiterals().  Literal: "
                    << YELLOW << "\"" << *literalIt << "\"." << WHITE << std::endl;
                    returnVal = false;
                }
            }
        }
        else
        {
            std::cout << RED << "wcharLiterals and wcharLiteralConversions are different sizes." << WHITE << std::endl;
            returnVal = false;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}

// Bad input ------------------------------------------------------------------

bool handleBadIntLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_int(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_int() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadIntLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test out of range
        testLiteral = "99999999999999999999";
        {
            try
            {
                HotConsts::_convertLiteralTo_int(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_int() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
            }
            catch (std::invalid_argument& e)
            {
                std::cout << RED << "std::invalid_argument thrown in test handleBadIntLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
        }
        // Test extra characters
        testLiteral = "123asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_int(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_int() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadIntLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'int' literal: " <<
        YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool handleBadLongLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_long(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_long() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test out of range
        testLiteral = "99999999999999999999L";
        {
            try
            {
                HotConsts::_convertLiteralTo_long(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_long() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
            }
            catch (std::invalid_argument& e)
            {
                std::cout << RED << "std::invalid_argument thrown in test handleBadLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
        }
        // Test extra characters
        testLiteral = "123asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_long(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_long() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'long' literal: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool handleBadLongLongLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_longlong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_longlong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadLongLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test out of range
        testLiteral = "99999999999999999999LL";
        {
            try
            {
                HotConsts::_convertLiteralTo_longlong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_longlong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
            }
            catch (std::invalid_argument& e)
            {
                std::cout << RED << "std::invalid_argument thrown in test handleBadLongLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
        }
        // Test extra characters
        testLiteral = "123asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_longlong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_longlong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadLongLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'long long' literal: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool handleBadUIntLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_uint(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_uint() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadUIntLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test out of range
        testLiteral = "99999999999999999999U";
        {
            try
            {
                HotConsts::_convertLiteralTo_uint(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_uint() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
            }
            catch (std::invalid_argument& e)
            {
                std::cout << RED << "std::invalid_argument thrown in test handleBadUIntLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
        }
        // Test extra characters
        testLiteral = "123asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_uint(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_uint() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadUIntLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'unsigned int' literal: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool handleBadULongLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_ulong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_ulong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadULongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test out of range
        testLiteral = "99999999999999999999UL";
        {
            try
            {
                HotConsts::_convertLiteralTo_ulong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_ulong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
            }
            catch (std::invalid_argument& e)
            {
                std::cout << RED << "std::invalid_argument thrown in test handleBadULongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
        }
        // Test extra characters
        testLiteral = "123asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_ulong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_ulong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadULongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'unsigned long' literal: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool handleBadULongLongLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_ulonglong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_ulonglong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadULongLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test out of range
        testLiteral = "99999999999999999999ULL";
        {
            try
            {
                HotConsts::_convertLiteralTo_ulonglong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_ulonglong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
            }
            catch (std::invalid_argument& e)
            {
                std::cout << RED << "std::invalid_argument thrown in test handleBadULongLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
        }
        // Test extra characters
        testLiteral = "123asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_ulonglong(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_ulonglong() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadULongLongLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'unsigned long long' literal: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}

bool handleBadDoubleLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_double(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_double() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadDoubleLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test extra characters
        testLiteral = "1.23asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_double(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_double() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadDoubleLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'double' literal: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool handleBadFloatLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_float(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_float() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadFloatLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test extra characters
        testLiteral = "1.23fasdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_float(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_float() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadFloatLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'float' literal: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
bool handleBadLongDoubleLiterals()
{
    bool returnVal = true;
    
    try
    {
        // Test conversion failure
        std::string testLiteral = "asdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_longdouble(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_longdouble() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadLongDoubleLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
        // Test extra characters
        testLiteral = "1.23lasdf";
        {
            try
            {
                HotConsts::_convertLiteralTo_longdouble(testLiteral, HotConsts::literalBase::decimal);
                std::cout << RED << "convertLiteralTo_longdouble() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::out_of_range& e)
            {
                std::cout << RED << "std::out_of_range thrown in test handleBadLongDoubleLiterals().  Literal: "
                << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl;
                returnVal = false;
            }
            catch (std::invalid_argument& e)
            {
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad 'long double' literal: " << YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}

bool handleBadBoolLiterals()
{
    bool returnVal = true;
    
    std::string testStr = "asdf";
    {
        try
        {
            HotConsts::_convertLiteralTo_bool(testStr);
            std::cout << RED << "convertLiteralTo_bool() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testStr << "\"" << RED << "." << WHITE << std::endl;
            returnVal = false;
        }
        catch (std::invalid_argument& e)
        {
        }
    }
    testStr = "trueasdf";
    {
        try
        {
            HotConsts::_convertLiteralTo_bool(testStr);
            std::cout << RED << "convertLiteralTo_bool() reports successful conversion of bad literal " << YELLOW <<
                "\"" << testStr << "\"" << RED << "." << WHITE << std::endl;
            returnVal = false;
        }
        catch (std::invalid_argument& e)
        {
        }
    }
    return returnVal;
}

#define BADCHARTEST_SHOULDBEOOR(TESTLITERAL, CONVERSIONFN) \
testLiteral = TESTLITERAL; \
{ \
    try \
    { \
        HotConsts:: CONVERSIONFN (testLiteral); \
        std::cout << RED << #CONVERSIONFN "() reports successful conversion of bad literal " << YELLOW << \
        "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl; \
        returnVal = false; \
    } \
    catch (std::out_of_range& e) \
    { \
    } \
    catch (std::invalid_argument& e) \
    { \
        std::cout << RED << "std::invalid_argument thrown in test " #CONVERSIONFN "().  Literal: " \
        << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl; \
        returnVal = false; \
    } \
}
#define BADCHARTEST_SHOULDBEINVALIDARG(TESTLITERAL, CONVERSIONFN) \
testLiteral = TESTLITERAL; \
{ \
    try \
    { \
        HotConsts:: CONVERSIONFN (testLiteral); \
        std::cout << RED << #CONVERSIONFN "() reports successful conversion of bad literal " << YELLOW << \
        "\"" << testLiteral << "\"" << RED << "." << WHITE << std::endl; \
        returnVal = false; \
    } \
    catch (std::out_of_range& e) \
    { \
        std::cout << RED << "std::out_of_range thrown in test " #CONVERSIONFN "().  Literal: " \
        << YELLOW << "\"" << testLiteral << "\"." << WHITE << std::endl; \
        returnVal = false; \
    } \
    catch (std::invalid_argument& e) \
    { \
    } \
}
bool handleBadCharLiterals()
{
    std::string testLiteral;
    bool returnVal = true;
    
    try
    {
        // no characters between ''.
        BADCHARTEST_SHOULDBEINVALIDARG("\'\'", _convertLiteralTo_char);
        
        // invalid characters after final '.
        BADCHARTEST_SHOULDBEINVALIDARG("\'c\'abc", _convertLiteralTo_char); // 'c'abc
        
        // missing final '.
        BADCHARTEST_SHOULDBEINVALIDARG("\'", _convertLiteralTo_char); // '
        BADCHARTEST_SHOULDBEINVALIDARG("\'c", _convertLiteralTo_char); // 'c
        
        // too many characters between '' (multicharacter)
        BADCHARTEST_SHOULDBEINVALIDARG("\'abc\'", _convertLiteralTo_char); // 'abc'
        
        // nonstandard escape sequence
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\z\'", _convertLiteralTo_char); // '\z'
        
        // too many characters after valid escape sequence (multicharacter)
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\nabc\'", _convertLiteralTo_char); // '\nabc'
        
        // octal character limit
        BADCHARTEST_SHOULDBEOOR("\'\\400\'", _convertLiteralTo_char); // '\400'
        
        // hexadecimal character limits
        BADCHARTEST_SHOULDBEOOR("\'\\x100\'", _convertLiteralTo_char); // '\x100'
        BADCHARTEST_SHOULDBEOOR("u8\'\\x100\'", _convertLiteralTo_char8); // '\x100'
        BADCHARTEST_SHOULDBEOOR("u\'\\x10000\'", _convertLiteralTo_char16); // '\x10000'
        BADCHARTEST_SHOULDBEOOR("U\'\\x100000000\'", _convertLiteralTo_char32); // '\x100000000'
        // Derive the string representation of the escape character greater than the max of wchar_t
        char buffer[16];
        sprintf(buffer, "%llX", RANGEOFTYPE(wchar_t) + 1);
        BADCHARTEST_SHOULDBEOOR("L\'\\x" + std::string(buffer) + "\'", _convertLiteralTo_wchar);
        
        // too few characters in unicode character names
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\u40\'", _convertLiteralTo_char); // '\u40'
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\U000040\'", _convertLiteralTo_char); // '\U000040'
        
        // extra characters after octal, hex, and unicode esc sequences
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\377c\'", _convertLiteralTo_char); // '\377c'
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\0c'", _convertLiteralTo_char); // '\0c'
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\xFFz\'", _convertLiteralTo_char); // '\xFFz'
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\u0040z\'", _convertLiteralTo_char); // '\u0040z'
        BADCHARTEST_SHOULDBEINVALIDARG("\'\\U00000040z\'", _convertLiteralTo_char); // '\U00000040z'
        
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Unhandled exception caught during conversion of bad character literal: " <<
        YELLOW << e.what() << WHITE << std::endl;
        returnVal = false;
    }
    
    return returnVal;
}
