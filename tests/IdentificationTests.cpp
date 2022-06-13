#include "_tests.h"
#include "LiteralSamples.h"
#include <HotConsts/HotConsts.h>
#include <iostream>

bool identifyIntLiterals()
{
	bool returnVal = true;

	if (intLiterals.size() == intLiteralIdentities.size())
	{
		auto identityIt = intLiteralIdentities.begin();
		for (auto literalIt = intLiterals.begin();
			 literalIt != intLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "The literal " << YELLOW << "\"" << *literalIt << "\"" << RED
					<< " was identified incorrectly." << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "intLiterals and intLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyLongLiterals()
{
	bool returnVal = true;

	if (longLiterals.size() == longLiteralIdentities.size())
	{
		auto identityIt = longLiteralIdentities.begin();
		for (auto literalIt = longLiterals.begin();
			 literalIt != longLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "The literal " << YELLOW << "\"" << *literalIt << "\"" << RED
					<< " was identified incorrectly." << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "longLiterals and longLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyLongLongLiterals()
{
	bool returnVal = true;

	if (longlongLiterals.size() == longlongLiteralIdentities.size())
	{
		auto identityIt = longlongLiteralIdentities.begin();
		for (auto literalIt = longlongLiterals.begin();
			 literalIt != longlongLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "The literal " << YELLOW << "\"" << *literalIt << "\"" << RED
					<< " was identified incorrectly." << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "longlongLiterals and longlongLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyUIntLiterals()
{
	bool returnVal = true;

	if (uintLiterals.size() == uintLiteralIdentities.size())
	{
		auto identityIt = uintLiteralIdentities.begin();
		for (auto literalIt = uintLiterals.begin();
			 literalIt != uintLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "The literal " << YELLOW << "\"" << *literalIt << "\"" << RED
					<< " was identified incorrectly." << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "uintLiterals and uintLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyULongLiterals()
{
	bool returnVal = true;

	if (ulongLiterals.size() == ulongLiteralIdentities.size())
	{
		auto identityIt = ulongLiteralIdentities.begin();
		for (auto literalIt = ulongLiterals.begin();
			 literalIt != ulongLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "The literal " << YELLOW << "\"" << *literalIt << "\"" << RED
					<< " was identified incorrectly." << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "ulongLiterals and ulongLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyULongLongLiterals()
{
	bool returnVal = true;

	if (ulonglongLiterals.size() == ulonglongLiteralIdentities.size())
	{
		auto identityIt = ulonglongLiteralIdentities.begin();
		for (auto literalIt = ulonglongLiterals.begin();
			 literalIt != ulonglongLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "The literal " << YELLOW << "\"" << *literalIt << "\"" << RED
					<< " was identified incorrectly." << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "ulonglongLiterals and ulonglongLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyFloatLiterals()
{
	bool returnVal = true;

	if (floatLiterals.size() == floatLiteralIdentities.size())
	{
		auto identityIt = floatLiteralIdentities.begin();
		for (auto literalIt = floatLiterals.begin();
			 literalIt != floatLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "Failure to identify float literal "
					<< YELLOW << "\"" << *literalIt << "\"" << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "floatLiterals and floatLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyDoubleLiterals()
{
	bool returnVal = true;

	if (doubleLiterals.size() == doubleLiteralIdentities.size())
	{
		auto identityIt = doubleLiteralIdentities.begin();
		for (auto literalIt = doubleLiterals.begin();
			 literalIt != doubleLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "Failure to identify double literal "
					<< YELLOW << "\"" << *literalIt << "\"" << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "doubleLiterals and doubleLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyLongDoubleLiterals()
{
	bool returnVal = true;

	if (longDoubleLiterals.size() == longDoubleLiteralIdentities.size())
	{
		auto identityIt = longDoubleLiteralIdentities.begin();
		for (auto literalIt = longDoubleLiterals.begin();
			 literalIt != longDoubleLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "Failure to identify long double literal "
					<< YELLOW << "\"" << *literalIt << "\"" << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "longDoubleLiterals and longDoubleLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyCharLiterals()
{
	bool returnVal = true;

	if (charLiterals.size() == charLiteralIdentities.size())
	{
		auto identityIt = charLiteralIdentities.begin();
		for (auto literalIt = charLiterals.begin();
			 literalIt != charLiterals.end();
			 ++literalIt)
		{
			if (HotConsts::_identifyArithmeticLiteral(*literalIt) != *identityIt)
			{
				std::cout << RED << "Failure to identify character literal "
					<< YELLOW << "\"" << *literalIt << "\"" << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "charLiterals and charLiteralIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyBoolLiterals()
{
	std::string testStr = "true";
	if (HotConsts::_identifyArithmeticLiteral(testStr) != std::pair(HotConsts::literalType::lit_bool, HotConsts::literalBase::notapplicable))
	{
		std::cout << RED << "Failure to identify boolean literal " << YELLOW << "\"true\"" << WHITE << std::endl;
		return false;
	}
	testStr = "false";
	if (HotConsts::_identifyArithmeticLiteral(testStr) != std::pair(HotConsts::literalType::lit_bool, HotConsts::literalBase::notapplicable))
	{
		std::cout << RED << "Failure to identify boolean literal " << YELLOW << "\"false\"" << WHITE << std::endl;
		return false;
	}
	return true;
}

bool identifyOperators()
{
	bool returnVal = true;

	if (operatorTokens.size() == operatorIdentities.size())
	{
		auto identityIt = operatorIdentities.begin();
		for (auto tokenIt = operatorTokens.begin();
			 tokenIt != operatorTokens.end();
			 ++tokenIt)
		{
			if (HotConsts::_identifyOperator(*tokenIt) != *identityIt)
			{
				std::cout << RED << "Failure to identify operator token "
					<< YELLOW << "\"" << *tokenIt << "\"" << WHITE << std::endl;
				returnVal = false;
			}
			++identityIt;
		}
	}
	else
	{
		std::cout << RED << "operatorTokens and operatorIdentities are different sizes." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}

bool identifyUnaryOperators()
{
	bool returnVal = true;
	std::string testToken;

	testToken = "+";
	if (HotConsts::_identifyUnaryOperator(testToken) != HotConsts::unaryOperationType::unary_plus)
	{
		std::cout << RED << "Failure to identify unary operator token " << YELLOW
			<< "\"" << testToken << "\"" << RED << "." << WHITE << std::endl;
		returnVal = false;
	}
	testToken = "-";
	if (HotConsts::_identifyUnaryOperator(testToken) != HotConsts::unaryOperationType::unary_minus)
	{
		std::cout << RED << "Failure to identify unary operator token " << YELLOW
			<< "\"" << testToken << "\"" << RED << "." << WHITE << std::endl;
		returnVal = false;
	}
	testToken = "!";
	if (HotConsts::_identifyUnaryOperator(testToken) != HotConsts::unaryOperationType::logical_NOT)
	{
		std::cout << RED << "Failure to identify unary operator token " << YELLOW
			<< "\"" << testToken << "\"" << RED << "." << WHITE << std::endl;
		returnVal = false;
	}
	testToken = "~";
	if (HotConsts::_identifyUnaryOperator(testToken) != HotConsts::unaryOperationType::bitwise_NOT)
	{
		std::cout << RED << "Failure to identify unary operator token " << YELLOW
			<< "\"" << testToken << "\"" << RED << "." << WHITE << std::endl;
		returnVal = false;
	}

	return returnVal;
}
