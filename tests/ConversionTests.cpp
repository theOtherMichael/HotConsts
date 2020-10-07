#include <HotConsts/HotConsts.h>
#include "_tests.h"
#include "LiteralSamples.h"

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
	return false;
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
bool handleBadCharLiterals()
{
	return false;
}
