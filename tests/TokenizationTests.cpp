#include "_tests.h"
#include <HotConsts/HotConsts.h>

std::string testStrIn, testStrOut;

bool tokenizeEmptyExpr()
{
	// Empty expression
	testStrOut = "";
	HotConsts::_tokenizeArithmeticExpr(testStrOut);
	return testStrOut == "";
}

bool tokenizeTrivialExpr()
{
	// Trivial expression
	testStrOut = "1";
	HotConsts::_tokenizeArithmeticExpr(testStrOut);
	return testStrOut == "1";
}

bool tokenizeFloatWithNegativeExponent()
{
	// Floating point negative exponents
	testStrOut = "-1e-1-1E-1-0x1p-1-0x1P-1-";
	HotConsts::_tokenizeArithmeticExpr(testStrOut);
	return testStrOut == "- 1e-1 - 1E-1 - 0x1p-1 - 0x1P-1 -";
}

bool tokenizeOperators()
{
	// All operators
	testStrOut = "(1)2~3*4/5%6+7-8^9!10!=11<12<<13<=14<=>15>16>>17>=18&19&&20|21||22";
	HotConsts::_tokenizeArithmeticExpr(testStrOut);
	return testStrOut == "( 1 ) 2 ~ 3 * 4 / 5 % 6 + 7 - 8 ^ 9 ! 10 != 11 < 12 << 13 <= 14 <=> 15 > 16 >> 17 >= 18 & 19 && 20 | 21 || 22";
}

bool skipSpacesInTokenize()
{
	// Ensure spaces don't get doubled-up
	testStrOut = "( 1 ) 2 ~ 3 * 4 / 5 % 6 + 7 - 8 ^ 9 ! 10 != 11 < 12 << 13 <= 14 <=> 15 > 16 >> 17 >= 18 & 19 && 20 | 21 || 22";
	HotConsts::_tokenizeArithmeticExpr(testStrOut);
	return testStrOut == "( 1 ) 2 ~ 3 * 4 / 5 % 6 + 7 - 8 ^ 9 ! 10 != 11 < 12 << 13 <= 14 <=> 15 > 16 >> 17 >= 18 & 19 && 20 | 21 || 22";
}
