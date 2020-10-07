#pragma once

// Output text color switches
constexpr auto WHITE = "\x1b[0m";
constexpr auto RED = "\x1b[91m";
constexpr auto GREEN = "\x1b[92m";
constexpr auto YELLOW = "\x1b[93m";

// TOKENIZATION TESTS

// Tokenization
bool tokenizeEmptyExpr();
bool tokenizeTrivialExpr();
bool tokenizeFloatWithNegativeExponent();
bool tokenizeOperators();
bool skipSpacesInTokenize();

// IDENTIFICATION TESTS

// Literal Identification
bool identifyIntLiterals();
bool identifyLongLiterals();
bool identifyLongLongLiterals();
bool identifyUIntLiterals();
bool identifyULongLiterals();
bool identifyULongLongLiterals();

bool identifyFloatLiterals();
bool identifyDoubleLiterals();
bool identifyLongDoubleLiterals();

bool identifyBoolLiterals();
bool identifyCharLiterals();
//bool identifyStringLiterals();
bool identifyOperators();
bool identifyUnaryOperators();

// CONVERSION TESTS

// Literal Conversion
bool convertIntLiterals();
bool convertLongLiterals();
bool convertLongLongLiterals();
bool convertUIntLiterals();
bool convertULongLiterals();
bool convertULongLongLiterals();
bool conversionPromotesIntegers();

bool convertDoubleLiterals();
bool convertFloatLiterals();
bool convertLongDoubleLiterals();

bool convertCharLiterals();
bool convertBoolLiterals();

// Handle Literal Conversion Failure
bool handleBadIntLiterals();
bool handleBadLongLiterals();
bool handleBadLongLongLiterals();
bool handleBadUIntLiterals();
bool handleBadULongLiterals();
bool handleBadULongLongLiterals();

bool handleBadDoubleLiterals();
bool handleBadFloatLiterals();
bool handleBadLongDoubleLiterals();

bool handleBadCharLiterals();
bool handleBadBoolLiterals();

// OPERATOR TESTS

// Operation Evaluation
bool handleModuloWithIntegralOperands();
bool handleBitShiftLeftWithIntegralOperands();
bool handleBitShiftRightWithIntegralOperands();

bool handleModuloWithNonIntegralOperands();
bool handleBitShiftLeftWithNonIntegralOperands();
bool handleBitShiftRightWithNonIntegralOperands();
bool handleDivideByZero();

// Unary Operator Evaluation
bool evalUnaryPlus();
bool evalUnaryMinus();
bool evalLogicalNot();
bool evalBinaryNot();

// Comparison Operator Output Types
bool ltOutputIsBoolType();
bool ltoreqOutputIsBoolType();
bool gtOutputIsBoolType();
bool gtoreqOutputIsBoolType();
bool eqOutputIsBoolType();
bool neqOutputIsBoolType();

// Logical Operator Output Types
bool logicalANDOutputIsBoolType();
bool logicalOROutputIsBoolType();

// Unary Operator Output Types
bool logicalNOTOutputIsBoolType();

// EXPRESSION TESTS

// Ungrouped Expression Evaluation
bool simpleUnaryExpression();
bool complexUnaryExpression();
bool simpleBinaryExpression();
bool simpleBinaryExprWithUnaryOperator();
bool simpleBinaryExprWithComplexUnaryOperator();
bool chainBinaryExpr_EqualPrecedence();
bool chainBinaryExpr_DecreasingPrecedence();
bool chainBinaryExpr_IncreasingPrecedence();
bool chainBinaryExpr_EqPrecedenceWithUnaryOps();
bool chainBinaryExpr_DecPrecedenceWithUnaryOps();
bool chainBinaryExpr_IncPrecedenceWithUnaryOps();
bool chainBinaryExpr_EqPrWithComplexUnaryOps();
bool chainBinaryExpr_DecPrWithComplexUnaryOps();
bool chainBinaryExpr_IncPrWithComplexUnaryOps();

// Grouped Expression Evaluation
bool trivialParentheses();
bool parenthesesWithUnaryOperator();
bool parenthesesWithComplexUnaryOperator();
bool parenthesesTakePrecedence();
bool parenthesesTakePrecedenceWithUnaryOp();
bool parenthesesTakePrecWithComplexUnaryOp();
bool nestedParentheses();
bool nestedParenthesesWithUnaryOperators();
bool nestedParenthesesWithComplexUnaryOps();
bool separateParenthesesGroups();
bool separateParenthesesGroupsWithUnaryOps();
bool separateParenthesesGroupsWithComplexUnaryOps();

// Ultra Expression Evaluation
bool ultraExpressionEval();

// Bad Expression Handling
bool unpairedOpenParentheses();
bool unpairedCloseParentheses();
bool unexpectedOpenParentheses();
bool unexpectedCloseParentheses();
bool unexpectedNonLiteral();
bool unexpectedNonOperator();
bool missingFinalLiteral();
bool badFinalExpressionConversion();

// Memory leaks
bool noMemoryLeaks();

// RELOAD TESTS

// Source code comment parsing
bool handleSingleLineComments();
bool handleSingleLineCommentsInStrings();
bool handleMultiLineComments();
bool handleMultiLineCommentsInStrings();

// Source code reload
bool reloadSimpleHC();
bool reloadSingleHCWithTypeModifier();
bool reloadSingleHCWithLineBreaks();
bool reloadSingleHCWithTypeModifierAndLineBreaks();
bool reloadMultipleHCs();
bool reloadMutipleHCsSingleLine();
bool reloadIgnoresMacroInStrings();
bool reloadSkipsSymbolsContainingHC();

// Bad source code reload
bool reloadCatchesFileOpenFailure();
bool reloadHandlesBadParams();
bool reloadHandlesBadAssignment();
bool reloadHandlesNewParams();
bool reloadHandlesRedefinitions(); //
bool reloadHandlesEOF_awaitingLParentheses();
bool reloadHandlesEOF_awaitingParam1();
bool reloadHandlesEOF_awaitingComma();
bool reloadHandlesEOF_awaitingParam2();
bool reloadHandlesEOF_awaitingRParentheses();
bool reloadHandlesEOF_awaitingAssignmentOperator();
bool reloadHandlesEOF_awaitingSemicolon();

// Reload Mechanism
bool fileChangeTriggersReload();
