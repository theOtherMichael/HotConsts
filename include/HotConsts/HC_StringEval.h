#pragma once

/*
    HC_StringEval.h
    Evaluation of non-arithmetic expressions into strings during reload.
*/


// Evaluate a string as a non-arithmetic expression.
template <typename T>
T _nonArithmeticEval(std::string& strExpr, bool& successful)
{
    successful = false;
    return '0';
}
