#include <HotConsts/HotConsts.h>
#include "_tests.h"

/*
    Tests evaluation of individual operations.
*/


// Operation Evaluation -------------------------------------------------------

bool handleModuloWithIntegralOperands()
{
    bool returnVal = true;
    auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<int, int>(1, 1, HotConsts::operationType::modulo);
    if (!evalSuccessful)
    {
        std::cout << RED << "EvaluateOperation() reports unsuccessful evaluation of '%' operator with integral operand(s).  "
            "Expression: " << YELLOW << "\"1 % 1\"" << WHITE << std::endl;
        returnVal = false;
    }
    return returnVal;
}
bool handleBitShiftLeftWithIntegralOperands()
{
    bool returnVal = true;
    auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<int, int>(1, 1, HotConsts::operationType::bitshift_left);
    if (!evalSuccessful)
    {
        std::cout << RED << "EvaluateOperation() reports unsuccessful evaluation of '<<' operator with integral operand(s).  "
            "Expression: " << YELLOW << "\"1 << 1\"" << WHITE << std::endl;
        returnVal = false;
    }
    return returnVal;
}
bool handleBitShiftRightWithIntegralOperands()
{
    bool returnVal = true;
    auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<int, int>(1, 1, HotConsts::operationType::bitshift_right);
    if (!evalSuccessful)
    {
        std::cout << RED << "EvaluateOperation() reports unsuccessful evaluation of '>>' operator with integral operand(s).  "
            "Expression: " << YELLOW << "\"1 >> 1\"" << WHITE << std::endl;
        returnVal = false;
    }
    return returnVal;
}
bool handleModuloWithNonIntegralOperands()
{
    bool returnVal = true;
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<float, int>(1.0f, 1, HotConsts::operationType::modulo);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '%' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1.0f % 1\"" << WHITE << std::endl;
            returnVal = false;
        }
    }
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<int, float>(1, 1.0f, HotConsts::operationType::modulo);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '%' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1 % 1.0f\"" << WHITE << std::endl;
            returnVal = false;
        }
    }
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<float, float>(1.0f, 1.0f, HotConsts::operationType::modulo);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '%' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1.0f % 1.0f\"" << WHITE << std::endl;
            returnVal = false;
        }
    }
    return returnVal;
}
bool handleBitShiftLeftWithNonIntegralOperands()
{
    bool returnVal = true;
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<float, int>(1.0f, 1, HotConsts::operationType::bitshift_left);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '<<' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1.0f << 1\"" << WHITE << std::endl;
            returnVal = false;
        }
    }
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<int, float>(1, 1.0f, HotConsts::operationType::bitshift_left);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '<<' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1 << 1.0f\"" << WHITE << std::endl;
            returnVal = false;
        }
    }
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<float, float>(1.0f, 1.0f, HotConsts::operationType::bitshift_left);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '<<' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1.0f << 1.0f\"" << WHITE << std::endl;
            returnVal = false;
        }
    }
    return returnVal;
}
bool handleBitShiftRightWithNonIntegralOperands()
{
    bool returnVal = true;
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<float, int>(1.0f, 1, HotConsts::operationType::bitshift_right);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '>>' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1.0f >> 1\"" << WHITE << std::endl;
            returnVal = false;

        }
    }
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<int, float>(1, 1.0f, HotConsts::operationType::bitshift_right);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '>>' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1 >> 1.0f\"" << WHITE << std::endl;
            returnVal = false;
        }
    }
    {
        auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<float, float>(1.0f, 1.0f, HotConsts::operationType::bitshift_right);
        if (evalSuccessful)
        {
            std::cout << RED << "EvaluateOperation() reports successful evaluation of '>>' operator with non-integral operand(s).  "
                "Expression: " << YELLOW << "\"1.0f >> 1.0f\"" << WHITE << std::endl;
            returnVal = false;
        }
    }
    return returnVal;
}

bool handleDivideByZero()
{
    auto [evalSuccessful, evalResult] = HotConsts::_evaluateOp<float, float>(1.0f, 0.0f, HotConsts::operationType::divide);
    if (evalSuccessful)
    {
        std::cout << RED << "EvaluateOperation() reports successful evaluation of division by zero." << WHITE << std::endl;
        return false;
    }
    else
        return true;
}

// Unary Operator Evaluation --------------------------------------------------

bool evalUnaryPlus()
{
    bool returnVal = true;
    {
        auto evalResult = HotConsts::_evaluateUnaryOp(1, HotConsts::unaryOperationType::unary_plus);
        if (!evalResult.first)
            returnVal = false;
    }
    {
        auto evalResult = HotConsts::_evaluateUnaryOp(1.0, HotConsts::unaryOperationType::unary_plus);
        if (!evalResult.first)
            returnVal = false;
    }
    return returnVal;
}
bool evalUnaryMinus()
{
    bool returnVal = true;
    {
        auto evalResult = HotConsts::_evaluateUnaryOp(1, HotConsts::unaryOperationType::unary_minus);
        if (!evalResult.first)
            returnVal = false;
    }
    {
        auto evalResult = HotConsts::_evaluateUnaryOp(1.0, HotConsts::unaryOperationType::unary_minus);
        if (!evalResult.first)
            returnVal = false;
    }
    return returnVal;
}
bool evalLogicalNot()
{
    bool returnVal = true;
    {
        auto evalResult = HotConsts::_evaluateUnaryOp(1, HotConsts::unaryOperationType::logical_NOT);
        if (!evalResult.first)
            returnVal = false;
    }
    {
        auto evalResult = HotConsts::_evaluateUnaryOp(1.0, HotConsts::unaryOperationType::logical_NOT);
        if (!evalResult.first)
            returnVal = false;
    }
    return returnVal;
}
bool evalBinaryNot()
{
    bool returnVal = true;
    {
        auto evalResult = HotConsts::_evaluateUnaryOp(1, HotConsts::unaryOperationType::bitwise_NOT);
        if (!evalResult.first)
            returnVal = false;
    }
    {
        auto evalResult = HotConsts::_evaluateUnaryOp(1.0, HotConsts::unaryOperationType::bitwise_NOT);
        if (evalResult.first)
            returnVal = false;
    }
    return returnVal;
}

// Comparison Operator Output Types -------------------------------------------

bool ltOutputIsBoolType()
{
    bool returnVal = true;

    std::string LHS = "1";
    std::string RHS = "2";
    
    // This gets deleted by evalAndPopOperatorNode automatically
    HotConsts::ETOperator* testOp = new HotConsts::ETOperator;

    testOp->opType = HotConsts::operationType::compare_lt;
    testOp->lchild = HotConsts::_newETLeaf(LHS); //Popped automatically
    testOp->rchild = HotConsts::_newETLeaf(RHS); //Popped automatically

    auto resultPtr = HotConsts::_evalAndPopETOperator(testOp);
    if (resultPtr)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(resultPtr);
        if (!leafCast)
            returnVal = false;
        delete resultPtr;
    }
    else
        returnVal = false;

    //testOp is deleted whether or not the evaluation was successful.
    return returnVal;
}
bool ltoreqOutputIsBoolType()
{
    bool returnVal = true;

    std::string LHS = "1";
    std::string RHS = "2";

    // This gets deleted by evalAndPopOperatorNode automatically
    HotConsts::ETOperator* testOp = new HotConsts::ETOperator;

    testOp->opType = HotConsts::operationType::compare_ltoreq;
    testOp->lchild = HotConsts::_newETLeaf(LHS); //Popped automatically
    testOp->rchild = HotConsts::_newETLeaf(RHS); //Popped automatically

    auto resultPtr = HotConsts::_evalAndPopETOperator(testOp);
    if (resultPtr)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(resultPtr);
        if (!leafCast)
            returnVal = false;
        delete resultPtr;
    }
    else
        returnVal = false;

    //testOp is deleted whether or not the evaluation was successful.
    return returnVal;
}
bool gtOutputIsBoolType()
{
    bool returnVal = true;

    std::string LHS = "1";
    std::string RHS = "2";

    // This gets deleted by evalAndPopOperatorNode automatically
    HotConsts::ETOperator* testOp = new HotConsts::ETOperator;

    testOp->opType = HotConsts::operationType::compare_gt;
    testOp->lchild = HotConsts::_newETLeaf(LHS); //Popped automatically
    testOp->rchild = HotConsts::_newETLeaf(RHS); //Popped automatically

    auto resultPtr = HotConsts::_evalAndPopETOperator(testOp);
    if (resultPtr)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(resultPtr);
        if (!leafCast)
            returnVal = false;
        delete resultPtr;
    }
    else
        returnVal = false;

    //testOp is deleted whether or not the evaluation was successful.
    return returnVal;
}
bool gtoreqOutputIsBoolType()
{
    bool returnVal = true;

    std::string LHS = "1";
    std::string RHS = "2";

    // This gets deleted by evalAndPopOperatorNode automatically
    HotConsts::ETOperator* testOp = new HotConsts::ETOperator;

    testOp->opType = HotConsts::operationType::compare_gtoreq;
    testOp->lchild = HotConsts::_newETLeaf(LHS); //Popped automatically
    testOp->rchild = HotConsts::_newETLeaf(RHS); //Popped automatically

    auto resultPtr = HotConsts::_evalAndPopETOperator(testOp);
    if (resultPtr)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(resultPtr);
        if (!leafCast)
            returnVal = false;
        delete resultPtr;
    }
    else
        returnVal = false;

    //testOp is deleted whether or not the evaluation was successful.
    return returnVal;
}
bool eqOutputIsBoolType()
{
    bool returnVal = true;

    std::string LHS = "1";
    std::string RHS = "2";

    // This gets deleted by evalAndPopOperatorNode automatically
    HotConsts::ETOperator* testOp = new HotConsts::ETOperator;

    testOp->opType = HotConsts::operationType::compare_eq;
    testOp->lchild = HotConsts::_newETLeaf(LHS); //Popped automatically
    testOp->rchild = HotConsts::_newETLeaf(RHS); //Popped automatically

    auto resultPtr = HotConsts::_evalAndPopETOperator(testOp);
    if (resultPtr)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(resultPtr);
        if (!leafCast)
            returnVal = false;
        delete resultPtr;
    }
    else
        returnVal = false;

    //testOp is deleted whether or not the evaluation was successful.
    return returnVal;
}
bool neqOutputIsBoolType()
{
    bool returnVal = true;

    std::string LHS = "1";
    std::string RHS = "2";

    // This gets deleted by evalAndPopOperatorNode automatically
    HotConsts::ETOperator* testOp = new HotConsts::ETOperator;

    testOp->opType = HotConsts::operationType::compare_neq;
    testOp->lchild = HotConsts::_newETLeaf(LHS); //Popped automatically
    testOp->rchild = HotConsts::_newETLeaf(RHS); //Popped automatically

    auto resultPtr = HotConsts::_evalAndPopETOperator(testOp);
    if (resultPtr)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(resultPtr);
        if (!leafCast)
            returnVal = false;
        delete resultPtr;
    }
    else
        returnVal = false;

    //testOp is deleted whether or not the evaluation was successful.
    return returnVal;
}

// Logical Operator Output Types ----------------------------------------------

bool logicalANDOutputIsBoolType()
{
    bool returnVal = true;

    std::string LHS = "1";
    std::string RHS = "2";

    // This gets deleted by evalAndPopOperatorNode automatically
    HotConsts::ETOperator* testOp = new HotConsts::ETOperator;

    testOp->opType = HotConsts::operationType::logical_AND;
    testOp->lchild = HotConsts::_newETLeaf(LHS); //Popped automatically
    testOp->rchild = HotConsts::_newETLeaf(RHS); //Popped automatically

    auto resultPtr = HotConsts::_evalAndPopETOperator(testOp);
    if (resultPtr)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(resultPtr);
        if (!leafCast)
            returnVal = false;
        delete resultPtr;
    }
    else
        returnVal = false;

    //testOp is deleted whether or not the evaluation was successful.
    return returnVal;
}
bool logicalOROutputIsBoolType()
{
    bool returnVal = true;

    std::string LHS = "1";
    std::string RHS = "2";

    // This gets deleted by evalAndPopOperatorNode automatically
    HotConsts::ETOperator* testOp = new HotConsts::ETOperator;

    testOp->opType = HotConsts::operationType::logical_OR;
    testOp->lchild = HotConsts::_newETLeaf(LHS); //Popped automatically
    testOp->rchild = HotConsts::_newETLeaf(RHS); //Popped automatically

    auto resultPtr = HotConsts::_evalAndPopETOperator(testOp);
    if (resultPtr)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(resultPtr);
        if (!leafCast)
            returnVal = false;
        delete resultPtr; // The resulting object is normally deleted farther downstream than this.
    }
    else
        returnVal = false;

    //testOp is deleted whether or not the evaluation was successful.
    return returnVal;
}

// Unary Operator Output Types ------------------------------------------------

bool logicalNOTOutputIsBoolType()
{
    bool returnVal = true;

    std::string operand = "15";
    HotConsts::ETNode* testLeaf = HotConsts::_newETLeaf(operand); //Popped automatically
    testLeaf = HotConsts::_applyUnaryOpAndPopETLeaf(testLeaf, HotConsts::unaryOperationType::logical_NOT);
    if (testLeaf)
    {
        auto leafCast = dynamic_cast<HotConsts::ETLeaf<bool>*>(testLeaf);
        if (!leafCast)
            returnVal = false;
        delete testLeaf;
    }
    else
        returnVal = false;

    //testLeaf is deleted automatically, whether or not the evaluation was successful.
    return returnVal;
}
