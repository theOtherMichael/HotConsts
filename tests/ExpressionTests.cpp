#include "_tests.h"
#include <HotConsts/HotConsts.h>
#include <iostream>

// Helper function for comparing Hot Constants' evaluation against the compiler's.
template <typename Out_T>
bool expressionTest(std::string stringExpression, Out_T evaluatedExression)
{
	auto [evalSuccessful, evalResult] = HotConsts::_evalArithmeticExpression<Out_T>(stringExpression);
	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;
	if (evalSuccessful)
		return evalResult == evaluatedExression;
	else
		return false;
}

// Ungrouped Expression Evaluation --------------------------------------------

bool simpleUnaryExpression()
{
	auto evaluatedExpression = -1.0;
	return expressionTest("-1.0", evaluatedExpression);
}

bool complexUnaryExpression()
{
	auto evaluatedExpression = -+1.0;
	return expressionTest("-+1.0", evaluatedExpression);
}

bool simpleBinaryExpression()
{
	auto evaluatedExpression = 1.0-2.0;
	return expressionTest("1.0-2.0", evaluatedExpression);
}

bool simpleBinaryExprWithUnaryOperator()
{
	auto evaluatedExpression = 1.0-+2.0;
	return expressionTest("1.0-+2.0", evaluatedExpression);
}

bool simpleBinaryExprWithComplexUnaryOperator()
{
	auto evaluatedExpression = 1.0-+~2;
	return expressionTest("1.0-+~2", evaluatedExpression);
}

bool chainBinaryExpr_EqualPrecedence()
{
	auto evaluatedExpression = 1.0-2.0-3.0;
	return expressionTest("1.0-2.0-3.0", evaluatedExpression);
}

bool chainBinaryExpr_DecreasingPrecedence()
{
	auto evaluatedExpression = 1.0/2.0-3.0;
	return expressionTest("1.0/2.0-3.0", evaluatedExpression);
}

bool chainBinaryExpr_IncreasingPrecedence()
{
	auto evaluatedExpression = 1.0-2.0/3.0;
	return expressionTest("1.0-2.0/3.0", evaluatedExpression);
}

bool chainBinaryExpr_EqPrecedenceWithUnaryOps()
{
	auto evaluatedExpression = -1.0-+2.0-+3.0;
	return expressionTest("-1.0-+2.0-+3.0", evaluatedExpression);
}

bool chainBinaryExpr_DecPrecedenceWithUnaryOps()
{
	auto evaluatedExpression = -1.0/+2.0-+3.0;
	return expressionTest("-1.0/+2.0-+3.0", evaluatedExpression);
}

bool chainBinaryExpr_IncPrecedenceWithUnaryOps()
{
	auto evaluatedExpression = -1.0-+2.0/+3.0;
	return expressionTest("-1.0-+2.0/+3.0", evaluatedExpression);
}

bool chainBinaryExpr_EqPrWithComplexUnaryOps()
{
	auto evaluatedExpression = -~1*+~2-+~3;
	return expressionTest("-~1*+~2-+~3", evaluatedExpression);
}

bool chainBinaryExpr_DecPrWithComplexUnaryOps()
{
	auto evaluatedExpression = -~1*+~2-+~3;
	return expressionTest("-~1*+~2-+~3", evaluatedExpression);
}

bool chainBinaryExpr_IncPrWithComplexUnaryOps()
{
	auto evaluatedExpression = -~1-+~2*+~3;
	return expressionTest("-~1-+~2*+~3", evaluatedExpression);
}

bool spaceCharacterLiterals()
{
	char charExpr = ' ';
	char char8Expr = u8' '; // c++17 TODO: change to char8_t in c++20
	char16_t char16Expr = u' ';
	char32_t char32Expr = U' ';
	wchar_t wcharExpr = L' ';
	return expressionTest("' '", charExpr) &&
		   expressionTest("u8' '", char8Expr) &&
		   expressionTest("u' '", char16Expr) &&
		   expressionTest("U' '", char32Expr) &&
		   expressionTest("L' '", wcharExpr);
}

// Grouped Expression Evaluation ----------------------------------------------

bool trivialParentheses()
{
	auto evaluatedExpression = (1);
	return expressionTest("(1)", evaluatedExpression);
}

bool parenthesesWithUnaryOperator()
{
	auto evaluatedExpression = -(1-2-3);
	return expressionTest("-(1-2-3)", evaluatedExpression);
}

bool parenthesesWithComplexUnaryOperator()
{
	auto evaluatedExpression = -+(1-2-3);
	return expressionTest("-+(1-2-3)", evaluatedExpression);
}

bool parenthesesTakePrecedence()
{
	auto evaluatedExpression = 1.0/(2-3);
	return expressionTest("1.0/(2-3)", evaluatedExpression);
}

bool parenthesesTakePrecedenceWithUnaryOp()
{
	auto evaluatedExpression = 1.0/-(2-3);
	return expressionTest("1.0/-(2-3)", evaluatedExpression);
}

bool parenthesesTakePrecWithComplexUnaryOp()
{
	auto evaluatedExpression = 1.0/+-(2-3);
	return expressionTest("1.0/+-(2-3)", evaluatedExpression);
}

bool nestedParentheses()
{
	auto evaluatedExpression = 1.0/(2/(3-4))/5;
	return expressionTest("1.0/(2/(3-4))/5", evaluatedExpression);
}

bool nestedParenthesesWithUnaryOperators()
{
	auto evaluatedExpression = 1.0/-(2/-(3-4))/5;
	return expressionTest("1.0/-(2/-(3-4))/5", evaluatedExpression);
}

bool nestedParenthesesWithComplexUnaryOps()
{
	auto evaluatedExpression = 1.0/-+(2/-+(3-4))/5;
	return expressionTest("1.0/-+(2/-+(3-4))/5", evaluatedExpression);
}

bool separateParenthesesGroups()
{
	auto evaluatedExpression = (1.0-2.0)/(3.0-4.0);
	return expressionTest("(1.0-2.0)/(3.0-4.0)", evaluatedExpression);
}

bool separateParenthesesGroupsWithUnaryOps()
{
	auto evaluatedExpression = -(1.0-2.0)/-(3.0-4.0);
	return expressionTest("-(1.0-2.0)/-(3.0-4.0)", evaluatedExpression);
}

bool separateParenthesesGroupsWithComplexUnaryOps()
{
	auto evaluatedExpression = +-(1.0-2.0)/+-(3.0-4.0);
	return expressionTest("+-(1.0-2.0)/+-(3.0-4.0)", evaluatedExpression);
}

// Ultra Expression Evaluation --------------------------------------------

bool ultraExpressionEval()
{
	auto evaluatedExpression = +(!(1.5 > 2.5 < 3.5f >= 4.5f <= 5.5l == 6.5l != 7.5 && false || !true))
	+ -(~(((1 << 2 >> 3u & 4u) ^ 5l) | 6l) - +-(+3ul * -4ul) / ~5ull % ~- 6ull);
	return expressionTest("+(!(1.5 > 2.5 < 3.5f >= 4.5f <= 5.5l == 6.5l != 7.5 && false || !true)) "
		"+ -(~(1 << 2 >> 3u & 4u ^ 5l | 6l) - +-(+3ul * -4ul) / ~5ull % ~- 6ull)", evaluatedExpression);
}

// Bad Expression Handling ------------------------------------------------

bool unpairedOpenParentheses()
{
	std::string testExpr = "1.0 / (2 - 3";
	bool result = !HotConsts::_evalArithmeticExpression<double>(testExpr).first;
	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;
	return result;
}

bool unpairedCloseParentheses()
{
	std::string testExpr = "1.0 / 2 - 3)";
	bool result = !HotConsts::_evalArithmeticExpression<double>(testExpr).first;
	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;
	return result;
}

bool unexpectedOpenParentheses()
{
	std::string testExpr = "1.0 (2 - 3)";
	bool result = !HotConsts::_evalArithmeticExpression<double>(testExpr).first;
	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;
	return result;
}

bool unexpectedCloseParentheses()
{
	std::string testExpr = "1.0 / (2 - ) 3";
	bool result = !HotConsts::_evalArithmeticExpression<double>(testExpr).first;
	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;
	return result;
}

bool unexpectedNonLiteral()
{
	std::string testExpr = "1.0 / (2 - blah)";
	bool result = !HotConsts::_evalArithmeticExpression<double>(testExpr).first;
	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;
	return result;
}

bool unexpectedNonOperator()
{
	std::string testExpr = "1.0 blah (2 - 3)";
	bool result = !HotConsts::_evalArithmeticExpression<double>(testExpr).first;
	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;
	return result;
}

bool missingFinalLiteral()
{
	std::string testExpr = "1.0 / (2 - 3) +";
	bool result = !HotConsts::_evalArithmeticExpression<double>(testExpr).first;
	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;
	return result;
}

bool narrowingFinalConversion()
{
	// We're testing that the conversion from the type resulting from the expression doesn't result in a conversion error.
	std::string testExpr = "65535";
	auto result = HotConsts::_evalArithmeticExpression<short>(testExpr);

	if (HotConsts::_nodeCount != 0)
		std::cout << "There was a memory leak.  Undeleted ETNodes: " << HotConsts::_nodeCount << std::endl;

	if (result.first && result.second == (short)65535)
		return true;
	else
		return false;
}

// Memory leaks -----------------------------------------------------------

bool noMemoryLeaks()
{
	// TODO: overload constructors and destructors for ETNode, then check that
	// all destructors were called after performing all previous tests.

	if (HotConsts::_nodeCount != 0)
	{
		std::cout << "There were memory leaks while testing expressions.  Undeleted ETNodes: " <<
			HotConsts::_nodeCount << std::endl;
		return false;
	}
	else
		return true;
}
