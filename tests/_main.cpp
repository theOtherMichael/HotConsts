#include <algorithm>
#include <limits>
#include <HotConsts/HotConsts.h>
#include "_tests.h"


/*
	Hot Constants tests
	Quick'n'dirty test project for the Hot Constants library.
*/


// How many characters of a function name to display before cutting it off.
// Also used to justify the text.
constexpr auto _maxTestNameLength = 40;

// Runs a test function and displays its name and status in the console.
void RunTest(bool(*testfn)(), const char* testname)
{
	// Format test name for display in the console (right-justified with colon)
	std::string formattedName = testname;
	int namelen = formattedName.length();
	formattedName.insert(0, std::max(0, _maxTestNameLength - namelen), ' ');
	formattedName.resize(_maxTestNameLength);
	formattedName.append(": ");

	// Run the test and display its status
	if (testfn())
		std::cout << formattedName << GREEN << "Passed!" << WHITE << std::endl;
	else
		std::cout << RED << formattedName << "FAILED!" << WHITE << std::endl;
}

// Helper macros for running tests
#define TESTHEADER(name) std::cout << std::endl << YELLOW << name << ":" << WHITE << std::endl
#define TEST(name) RunTest(&name, #name)

int main()
{
	// Display floating point numbers at the highest precisions
	std::cout.precision(std::numeric_limits<long double>::max_digits10);

	// Run tests.
	TESTHEADER("Tokenization");
	TEST(tokenizeEmptyExpr);
	TEST(tokenizeTrivialExpr);
	TEST(tokenizeFloatWithNegativeExponent);
	TEST(tokenizeOperators);
	TEST(skipSpacesInTokenize);

	TESTHEADER("Integer Literal Identification");
	TEST(identifyIntLiterals);
	TEST(identifyLongLiterals);
	TEST(identifyLongLongLiterals);
	TEST(identifyUIntLiterals);
	TEST(identifyULongLiterals);
	TEST(identifyULongLongLiterals);

	TESTHEADER("Floating Point Literal Identification");
	TEST(identifyFloatLiterals);
	TEST(identifyDoubleLiterals);
	TEST(identifyLongDoubleLiterals);

	TESTHEADER("Other Literal Identification");
	TEST(identifyBoolLiterals);
	TEST(identifyCharLiterals);
	TEST(identifyOperators);
	TEST(identifyUnaryOperators);

	TESTHEADER("Integer Literal Conversion");
	TEST(convertIntLiterals);
	TEST(convertLongLiterals);
	TEST(convertLongLongLiterals);
	TEST(convertUIntLiterals);
	TEST(convertULongLiterals);
	TEST(convertULongLongLiterals);
    TEST(conversionPromotesIntegers);

	TESTHEADER("Floating Point Literal Conversion");
	TEST(convertDoubleLiterals);
	TEST(convertFloatLiterals);
	TEST(convertLongDoubleLiterals);

	TESTHEADER("Other Literal Conversion");
	//TEST(convertCharLiterals);
	TEST(convertBoolLiterals);

	TESTHEADER("Bad Integer Literal Handling");
	TEST(handleBadIntLiterals);
	TEST(handleBadLongLiterals);
	TEST(handleBadLongLongLiterals);
	TEST(handleBadUIntLiterals);
	TEST(handleBadULongLiterals);
	TEST(handleBadULongLongLiterals);

	TESTHEADER("Bad Floating Point Literal Handling");
	TEST(handleBadDoubleLiterals);
	TEST(handleBadFloatLiterals);
	TEST(handleBadLongDoubleLiterals);

	TESTHEADER("Bad Other Literal Handling");
	TEST(handleBadBoolLiterals);
	//TEST(handleBadCharLiterals);

	TESTHEADER("Operation Evaluation");
	TEST(handleModuloWithIntegralOperands);
	TEST(handleBitShiftLeftWithIntegralOperands);
	TEST(handleBitShiftRightWithIntegralOperands);
	TEST(handleModuloWithNonIntegralOperands);
	TEST(handleBitShiftLeftWithNonIntegralOperands);
    TEST(handleBitShiftRightWithNonIntegralOperands);
    TEST(handleDivideByZero);
    
    TESTHEADER("Unary Operator Evaluation");
    TEST(evalUnaryPlus);
    TEST(evalUnaryMinus);
    TEST(evalLogicalNot);
    TEST(evalBinaryNot);

    TESTHEADER("Comparison Operator Output Types");
    TEST(ltOutputIsBoolType);
    TEST(ltoreqOutputIsBoolType);
    TEST(gtOutputIsBoolType);
    TEST(gtoreqOutputIsBoolType);
    TEST(eqOutputIsBoolType);
    TEST(neqOutputIsBoolType);

    TESTHEADER("Logical Operator Output Types");
    TEST(logicalANDOutputIsBoolType);
    TEST(logicalOROutputIsBoolType);

	TESTHEADER("Unary Operator Output Types");
	TEST(logicalNOTOutputIsBoolType);
    
    TESTHEADER("Ungrouped Expression Evaluation");
    TEST(simpleUnaryExpression);
    TEST(complexUnaryExpression);
    TEST(simpleBinaryExpression);
    TEST(simpleBinaryExprWithUnaryOperator);
    TEST(simpleBinaryExprWithComplexUnaryOperator);
    TEST(chainBinaryExpr_EqualPrecedence);
    TEST(chainBinaryExpr_DecreasingPrecedence);
    TEST(chainBinaryExpr_IncreasingPrecedence);
    TEST(chainBinaryExpr_EqPrecedenceWithUnaryOps);
    TEST(chainBinaryExpr_DecPrecedenceWithUnaryOps);
    TEST(chainBinaryExpr_IncPrecedenceWithUnaryOps);
    TEST(chainBinaryExpr_EqPrWithComplexUnaryOps);
    TEST(chainBinaryExpr_DecPrWithComplexUnaryOps);
    TEST(chainBinaryExpr_IncPrWithComplexUnaryOps);

    TESTHEADER("Grouped Expression Evaluation");
    TEST(trivialParentheses);
    TEST(parenthesesWithUnaryOperator);
    TEST(parenthesesWithComplexUnaryOperator);
    TEST(parenthesesTakePrecedence);
    TEST(parenthesesTakePrecedenceWithUnaryOp);
    TEST(parenthesesTakePrecWithComplexUnaryOp);
    TEST(nestedParentheses);
    TEST(nestedParenthesesWithUnaryOperators);
    TEST(nestedParenthesesWithComplexUnaryOps);
    TEST(separateParenthesesGroups);
    TEST(separateParenthesesGroupsWithUnaryOps);
    TEST(separateParenthesesGroupsWithComplexUnaryOps);

    TESTHEADER("Ultra Expression Evaluation");
    TEST(ultraExpressionEval);

    TESTHEADER("Bad Expression Handling");
    TEST(unpairedOpenParentheses);
    TEST(unpairedCloseParentheses);
    TEST(unexpectedOpenParentheses);
    TEST(unexpectedCloseParentheses);
    TEST(unexpectedNonLiteral);
    TEST(unexpectedNonOperator);
    TEST(missingFinalLiteral);
    TEST(narrowingFinalConversion);
    
    TESTHEADER("Memory leaks");
    TEST(noMemoryLeaks);
    
    // RELOAD TESTS

    TESTHEADER("Source code comment parsing");
    TEST(handleSingleLineComments);
    TEST(handleSingleLineCommentsInStrings);
    TEST(handleMultiLineComments);
    TEST(handleMultiLineCommentsInStrings);

    TESTHEADER("Source code reload");
    TEST(reloadSimpleHC);
    TEST(reloadSingleHCWithTypeModifier);
    TEST(reloadSingleHCWithLineBreaks);
    TEST(reloadSingleHCWithTypeModifierAndLineBreaks);
    TEST(reloadMultipleHCs);
    TEST(reloadMutipleHCsSingleLine);
    TEST(reloadIgnoresMacroInStrings);
    TEST(reloadSkipsSymbolsContainingHC);

    TESTHEADER("Bad source code reload");
    TEST(reloadCatchesFileOpenFailure);
    TEST(reloadHandlesBadParams);
    TEST(reloadHandlesBadAssignment);
    TEST(reloadHandlesNewParams);
    TEST(reloadHandlesRedefinitions);
    TEST(reloadHandlesEOF_awaitingLParentheses);
    TEST(reloadHandlesEOF_awaitingParam1);
    TEST(reloadHandlesEOF_awaitingComma);
    TEST(reloadHandlesEOF_awaitingParam2);
    TEST(reloadHandlesEOF_awaitingRParentheses);
    TEST(reloadHandlesEOF_awaitingAssignmentOperator);
    TEST(reloadHandlesEOF_awaitingSemicolon);

    TESTHEADER("File watch");
    TEST(fileChangeTriggersReload);

	return 0;
}
