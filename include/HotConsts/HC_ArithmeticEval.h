#pragma once
#include "HC_LiteralConversions.h"

/*
    HC_ArithmeticEval.h
    Evaluation of arithmetic expressions during reload.
*/


// TODO: Properly strip out instrumentation code in non-test builds.
#define HOTCONSTS_INSTRUMENTATION 1

namespace HotConsts
{

// Expression Tree Stuff ===============================================================================================

#if HOTCONSTS_INSTRUMENTATION
extern int _nodeCount;
#endif // HOTCONSTS_INSTRUMENTATION

struct ETOperator;

// A node of an expression tree.
struct ETNode
{
    ETOperator* parent = nullptr;
    
    operationType opType = operationType::none; // The operation this node represents (if any).
    size_t priority = 0;                        // The priority level of this node.  Unused in leaves.
    literalType litType = literalType::none;    // If this node is an ETLeaf, what type of value is stored in it.

    #if HOTCONSTS_INSTRUMENTATION
	ETNode(literalType litType, operationType opType) : litType(litType), opType(opType) { _nodeCount++; };
	virtual ~ETNode() { _nodeCount--; };
    #else
	ETNode(literalType litType, operationType opType) : litType(litType), opType(opType) {};
	virtual ~ETNode() {};
    #endif

	bool operator <(const ETNode& other) const;  // Compares operator prcedence.
	bool operator >=(const ETNode& other) const; // Compares operator precedence.
};

// An operator node of an expression tree.
struct ETOperator : public ETNode
{
    ETNode* lchild = nullptr;
    ETNode* rchild = nullptr;
    
    ETOperator(operationType opType = operationType::none): ETNode(literalType::none, opType) {};
};

// A leaf node of an expression tree.  Contains a value.
template <typename T>
struct ETLeaf : public ETNode
{
    T m_value;

    ETLeaf(literalType type, T value): m_value(value), ETNode(type, operationType::none) {};
};

// Instantiates an ETLeaf containing a literal's converted value.
ETNode* _newETLeaf(std::string& lit);



// Cast the value of an ETLeaf to to type T.
template <typename T>
T _castETLeaf(ETNode* leaf)
{
    T returnVal{};
    
    switch (leaf->litType)
	{
	    case literalType::lit_int:
		    returnVal = dynamic_cast<ETLeaf<int>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<int>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<int>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    case literalType::lit_long:
		    returnVal = dynamic_cast<ETLeaf<long>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<long>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<long>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    case literalType::lit_longlong:
		    returnVal = dynamic_cast<ETLeaf<long long>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<long long>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<long long>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    case literalType::lit_uint:
		    returnVal = dynamic_cast<ETLeaf<unsigned int>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<unsigned int>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<unsigned int>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    case literalType::lit_ulong:
		    returnVal = dynamic_cast<ETLeaf<unsigned long>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<unsigned long>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<unsigned long>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    case literalType::lit_ulonglong:
		    returnVal = dynamic_cast<ETLeaf<unsigned long long>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<unsigned long long>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<unsigned long long>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    case literalType::lit_double:
		    returnVal = dynamic_cast<ETLeaf<double>*>(leaf)->m_value;
		    break;
	    case literalType::lit_float:
		    returnVal = dynamic_cast<ETLeaf<float>*>(leaf)->m_value;
		    break;
	    case literalType::lit_longdouble:
		    returnVal = dynamic_cast<ETLeaf<long double>*>(leaf)->m_value;
		    break;
	    case literalType::lit_bool:
		    returnVal = dynamic_cast<ETLeaf<bool>*>(leaf)->m_value;
		    break;
	    case literalType::lit_char:
		    returnVal = dynamic_cast<ETLeaf<char>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<char>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<char>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    //case literalType::lit_char8: // c++20
		   // returnVal = dynamic_cast<ETLeaf<char8_t>*>(leaf)->m_value;
		   // if (returnVal != dynamic_cast<ETLeaf<char8_t>*>(leaf)->m_value)
		   // {
                //std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                //    " constant value \"" << dynamic_cast<ETLeaf<char8_t>*>(leaf)->m_value <<
                //    "\".  Is your constant type wide enough for your value?" << std::endl;
		   // }
		   // break;
	    case literalType::lit_char16:
		    returnVal = dynamic_cast<ETLeaf<char16_t>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<char16_t>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<char16_t>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    case literalType::lit_char32:
		    returnVal = dynamic_cast<ETLeaf<char32_t>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<char32_t>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<char32_t>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    case literalType::lit_wchar:
		    returnVal = dynamic_cast<ETLeaf<wchar_t>*>(leaf)->m_value;
		    if (returnVal != dynamic_cast<ETLeaf<wchar_t>*>(leaf)->m_value)
		    {
                std::cout << "Hot Constants:  Warning: Data loss detected reloading"
                    " constant value \"" << dynamic_cast<ETLeaf<wchar_t>*>(leaf)->m_value <<
                    "\".  Is your constant type wide enough for your value?" << std::endl;
		    }
		    break;
	    default:
		    std::cout << "Hot Constants:  Arithmetic Evaluation Failure: _castETLeaf() called on an unhandled type!" << std::endl;
		    break;
	}
    
    return returnVal;
}


// Deletes an ETNode and all of its children.
void _popETNode(ETNode* node);


// Calculate the result of a binary operation (non-integral/mixed operands)
template <typename T_Left, typename T_Right,
    typename T_Out = typename std::common_type<T_Left, T_Right>::type,
    typename std::enable_if<!(std::is_integral<T_Left>::value &&
                              std::is_integral<T_Right>::value), T_Out>::type* = nullptr>
std::pair<bool, T_Out> _evaluateOp(T_Left left, T_Right right, operationType op)
{
    std::pair<bool, T_Out> returnVal;
    returnVal.first = true;

    // One of the operands is not integral.
    // Omit integral-only operations.
    switch (op)
    {
    case operationType::multiply:
        returnVal.second = left * right;
        break;
    case operationType::divide:
        if (right != 0)
            returnVal.second = left / right;
        else
        {
            std::cout << "Hot Constants:  Arithmetic Operation Error: Divide by zero.  Expression: \"" <<
                left << " / " << right << "\"." << std::endl;
            returnVal.first = false;
            returnVal.second = right;
        }
        break;
    case operationType::modulo:
        std::cout << "Hot Constants:  Arithmetic Operator Error: '%' requires both operands "
            "be of integral type.  Expression: \"" << left << " % " << right << "\"." << std::endl;
        returnVal.first = false;
        returnVal.second = right;
        break;
    case operationType::add:
        returnVal.second = left + right;
        break;
    case operationType::subtract:
        returnVal.second = left - right;
        break;
    case operationType::bitshift_left:
        std::cout << "Hot Constants:  Arithmetic Operator Error: '<<' requires both operands "
			"be of integral type.  Expression: \"" << left << " << " << right << "\"." << std::endl;
        returnVal.first = false;
        returnVal.second = right;
        break;
    case operationType::bitshift_right:
        std::cout << "Hot Constants:  Arithmetic Operator Error: '>>' requires both operands "
			"be of integral type.  Expression: \"" << left << " >> " << right << "\"." << std::endl;
        returnVal.first = false; 
        returnVal.second = right;
        break;
    //case operationType::compare_threeway: //c++20
    //    break;
    case operationType::compare_lt:
        returnVal.second = left < right;
        break;
    case operationType::compare_ltoreq:
        returnVal.second = left <= right;
        break;
    case operationType::compare_gt:
        returnVal.second = left > right;
        break;
    case operationType::compare_gtoreq:
        returnVal.second = left >= right;
        break;
    case operationType::compare_eq:
        returnVal.second = left == right;
        break;
    case operationType::compare_neq:
        returnVal.second = left != right;
        break;
    case operationType::bitwise_AND:
		std::cout << "Hot Constants:  Arithmetic Operator Error: '&' requires both operands "
			"be of integral type.  Expression: \"" << left << " >> " << right << "\"." << std::endl;
		returnVal.first = false;
		returnVal.second = right;
		break;
    case operationType::bitwise_XOR:
		std::cout << "Hot Constants:  Arithmetic Operator Error: '^' requires both operands "
			"be of integral type.  Expression: \"" << left << " >> " << right << "\"." << std::endl;
		returnVal.first = false;
		returnVal.second = right;
		break;
    case operationType::bitwise_OR:
		std::cout << "Hot Constants:  Arithmetic Operator Error: '|' requires both operands "
			"be of integral type.  Expression: \"" << left << " >> " << right << "\"." << std::endl;
		returnVal.first = false;
		returnVal.second = right;
		break;
    case operationType::logical_AND:
        returnVal.second = left && right;
        break;
    case operationType::logical_OR:
        returnVal.second = left || right;
        break;
    //case operationType::none: // used when popping the root node of an evaluation tree
    //    returnVal.second = right;
    //    break;
    default:
        std::cout << "Hot Constants:  Error: Unhandled operation attempted!  operationType: " 
            << size_t(op) << std::endl;
        returnVal.first = false;
        returnVal.second = right;
        break;
    }

    return returnVal;
}


// Calculate the result of an operation (integral operands).
template <typename T_Left, typename T_Right, 
    typename T_Out = typename std::common_type<T_Left, T_Right>::type,
    typename std::enable_if<(std::is_integral<T_Left>::value && 
                             std::is_integral<T_Right>::value), T_Out>::type* = nullptr>
std::pair<bool, T_Out> _evaluateOp(T_Left left, T_Right right, operationType op)
{
    std::pair<bool, T_Out> returnVal;
    returnVal.first = true;

    // Both operators are integral.
    // Include integral-only operations.
    switch (op)
    {
    case operationType::multiply:
        returnVal.second = left * right;
        break;
    case operationType::divide:
        returnVal.second = left / right;
        break;
    case operationType::modulo:
        returnVal.second = left % right;
        break;
    case operationType::add:
        returnVal.second = left + right;
        break;
    case operationType::subtract:
        returnVal.second = left - right;
        break;
    case operationType::bitshift_left:
        returnVal.second = left << right;
        break;
    case operationType::bitshift_right:
        returnVal.second = left >> right;
        break;
    //case operationType::compare_threeway: //c++20
    //    break;
    case operationType::compare_lt:
        returnVal.second = left < right;
        break;
    case operationType::compare_ltoreq:
        returnVal.second = left <= right;
        break;
    case operationType::compare_gt:
        returnVal.second = left > right;
        break;
    case operationType::compare_gtoreq:
        returnVal.second = left >= right;
        break;
    case operationType::compare_eq:
        returnVal.second = left == right;
        break;
    case operationType::compare_neq:
        returnVal.second = left != right;
        break;
	case operationType::bitwise_AND:
		returnVal.second = left & right;
		break;
	case operationType::bitwise_XOR:
		returnVal.second = left ^ right;
		break;
	case operationType::bitwise_OR:
		returnVal.second = left | right;
		break;
    case operationType::logical_AND:
        returnVal.second = left && right;
        break;
    case operationType::logical_OR:
        returnVal.second = left || right;
        break;
    //case operationType::none: // used when popping the root node of an evaluation tree
    //    returnVal.second = right;
    //    break;
    default:
        std::cout << "Hot Constants:  Error: Unhandled operation attempted!  operationType: "
            << size_t(op) << std::endl;
        returnVal.first = false;
        returnVal.second = right;
        break;
    }

    return returnVal;
}


// Calculate the result of a unary operation (non-integral operand).
template <typename T_In, typename T_Out = typename std::common_type<T_In>::type,
typename std::enable_if<!std::is_integral<T_In>::value, T_Out>::type* = nullptr>
std::pair<bool, T_Out> _evaluateUnaryOp(T_In operand, unaryOperationType op)
{
    std::pair<bool, T_Out> returnVal;
    returnVal.first = true;
    returnVal.second = T_Out{};
    
    switch (op) {
        case unaryOperationType::unary_plus:
            returnVal.second = +operand;
            break;
        case unaryOperationType::unary_minus:
            returnVal.second = -operand;
            break;
        case unaryOperationType::logical_NOT:
            returnVal.second = !operand;
            break;
        case unaryOperationType::bitwise_NOT:
            std::cout << "Hot Constants:  Arithmetic Operator Error: '~' requires integral operand.  "
            "Expression: \"" << "~" << operand << "\"." << std::endl;
            returnVal.first = false;
            returnVal.second = operand;
            break;
        default:
            std::cout << "Hot Constants:  Error: Unhandled unary operation attempted!  operationType: " << size_t(op) << std::endl;
            returnVal.first = false;
            returnVal.second = operand;
            break;
    }
    
    return returnVal;
}


// Evaluate a unary operation (integral operand).
template <typename T_In, typename T_Out = typename std::common_type<T_In>::type,
typename std::enable_if<std::is_integral<T_In>::value && !std::is_same<T_In, bool>::value, T_Out>::type* = nullptr>
std::pair<bool, T_Out> _evaluateUnaryOp(T_In operand, unaryOperationType op)
{
    std::pair<bool, T_Out> returnVal;
    returnVal.first = true;
    returnVal.second = T_Out{};
    
    switch (op) {
        case unaryOperationType::unary_plus:
            returnVal.second = +operand;
            break;
        case unaryOperationType::unary_minus:
            returnVal.second = -operand;
            break;
        case unaryOperationType::logical_NOT:
            returnVal.second = !operand;
            break;
        case unaryOperationType::bitwise_NOT:
            returnVal.second = ~operand;
            break;
        default:
            std::cout << "Hot Constants:  Unhandled unary operation attempted!  "
                "operationType: " << size_t(op) << std::endl;
            returnVal.first = false;
            returnVal.second = operand;
            break;
    }
    
    return returnVal;
}


// Evaluate a unary operation (boolean operand).
template <typename T_In, typename T_Out = typename std::common_type<T_In>::type,
typename std::enable_if<std::is_integral<T_In>::value && std::is_same<T_In, bool>::value, T_Out>::type* = nullptr>
std::pair<bool, T_Out> _evaluateUnaryOp(T_In operand, unaryOperationType op)
{
    std::pair<bool, T_Out> returnVal;
    returnVal.first = true;
    returnVal.second = T_Out{};
    
    switch (op) {
        case unaryOperationType::unary_plus:
            returnVal.second = +operand;
            break;
        case unaryOperationType::unary_minus:
            returnVal.second = -operand;
            break;
        case unaryOperationType::logical_NOT:
            returnVal.second = !operand;
            break;
        case unaryOperationType::bitwise_NOT:
            returnVal.second = true; // Bitwise negation of bool always evaluates to 'true'.
            break;
        default:
            std::cout << "Hot Constants:  Unhandled unary operation attempted!  "
                "operationType: " << size_t(op) << std::endl;
            returnVal.first = false;
            returnVal.second = operand;
            break;
    }
    
    return returnVal;
}


// Evaluates an ETOperator, pops it, then returns pointer to a new ETLeaf containing the result.
ETNode* _evalAndPopETOperator(ETOperator* op);


// Applies a unary operation to an ETLeaf, pops it, then returns pointer to a new ETLeaf containing the result.
ETNode* _applyUnaryOpAndPopETLeaf(ETNode* leaf, unaryOperationType op);


// Expression Evaluation Stuff =========================================================================================


// Separates all tokens in an arithmetic expression with spaces.
void _tokenizeArithmeticExpr(std::string& expr);


// Evaluate a string containing an arithmetic expression and return the result.
template <typename T>
std::pair<bool, T> _evalArithmeticExpression(std::string& strExpr)
{
    std::pair<bool, T> returnVal;
    returnVal.first = true; // true if evaluation is successful
    returnVal.second = T{}; // value if evaluation is successful

    // Set up a string stream
    _tokenizeArithmeticExpr(strExpr);
    std::istringstream exprStream(strExpr);
    std::string token; // TODO: Investigate use of string_view instead
    
    // Parser status tracking
    bool awaitingLiteral = true;
    int currentPriority = 0;

    // Buffer of pending unary operators.  First: operator enum, Second: priority level
    std::vector<std::pair<unaryOperationType, int>> unaryBuffer;
    
    // Expression Tree construction
    ETOperator root;             // Dereferenced at the end
    ETOperator * prevOperator = &root;               // The operator last added to the tree.
    ETOperator * currentOperator = new ETOperator;  // The operator we're about to add to the tree.
    ETNode * currentLeaf = nullptr;                 // The leaf we're about to add to the tree.
    
    while (exprStream >> token)
    {
        if (awaitingLiteral)
        {
            auto unaryOp = _identifyUnaryOperator(token);

            if (token == "(")
                currentPriority++;
            else if (token == ")")
            {
                std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Encountered unexpected ')' in expression \""
                    << strExpr << "\".  Confirm that all operators have right operands." << std::endl;
				
                // BURN THEM ALL
				delete currentOperator;
				_popETNode(root.rchild);

				returnVal.first = false;
				return returnVal;
            }
            else if (unaryOp != unaryOperationType::none)
                unaryBuffer.emplace_back(std::pair(unaryOp, currentPriority));
            else
            {
                // Appears to be a literal, so treat it like one.
                // Conversion failure will catch it if it's not.
                awaitingLiteral = false;
                
                // TODO: Handle ' ' parsing here (space is delimiter, so requires special handling).

                currentLeaf = _newETLeaf(token);
                if (!currentLeaf)
                {
                    std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Encountered invalid token \"" << token << 
                        "\" in expression \"" << strExpr << "\"." << std::endl;
					
					// BURN THEM ALL
					delete currentOperator;
					_popETNode(root.rchild);

					returnVal.first = false;
					return returnVal;
                }
                else
                {
					// Apply any pending unary operators to the literal.
					while (!unaryBuffer.empty())
					{
						if (unaryBuffer.back().second == currentPriority)
						{
							currentLeaf = _applyUnaryOpAndPopETLeaf(currentLeaf, unaryBuffer.back().first);
							unaryBuffer.pop_back();
							if (!currentLeaf)
							{
								std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Unary operator failure in expression \""
									<< strExpr << "\"." << std::endl;

                                // TODO: Test memory leaks in this scenario
								returnVal.first = false;
								return returnVal;
							}
						}
						else
							break;
					}
				}
			}
		}
		else
		{
			if (token == "(")
			{
				std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Encountered unexpected '(' in expression \""
					<< strExpr << "\".  Confirm that all '(' are preceded by operators." << std::endl;

                // BURN THEM ALL
                delete currentOperator;
                prevOperator->rchild = currentLeaf;
                _popETNode(root.rchild);
				
				returnVal.first = false;
				return returnVal;
            }
            else if (token == ")")
            {
                currentPriority--;
                if (currentPriority < 0)
                {
                    std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Encountered unexpected ')' in expression \""
                        << strExpr << "\".  Confirm that all ')' have a corresponding '('." << std::endl;
                    
                    // BURN THEM ALL
                    delete currentOperator;
                    prevOperator->rchild = currentLeaf;
                    _popETNode(root.rchild);

					returnVal.first = false;
					return returnVal;
                }
            }
            else if ((currentOperator->opType = _identifyOperator(token)) != operationType::none)
            {
                // Found an operator when we expected one.
                awaitingLiteral = true;
                currentOperator->priority = currentPriority;
                
                if (*prevOperator < *currentOperator)
                {
                    // 1. Set current value as left leaf of current node.
                    currentOperator->lchild = currentLeaf;
                    currentLeaf->parent = currentOperator;
                    
                    // 2. Set current node as right child of previous node.
                    prevOperator->rchild = currentOperator;
                    currentOperator->parent = prevOperator;
                    
                    // 3. Create new current node and shift the node pointers.
                    prevOperator = currentOperator;
                    currentOperator = new ETOperator;
                    currentLeaf = nullptr;
                }
                else
                {
                    // 1. Set current leaf to right operand of previous operator.
                    //prevOperator->rchild = currentLeaf;
                    //currentLeaf = nullptr;

                    // 2. Identify the highest operator of lower precedence between prevOperator and root.
                    ETNode * cursor1 = prevOperator;
                    while (*cursor1->parent >= *currentOperator)
                        cursor1 = cursor1->parent;

                    // 3. Insert the current operator below the first operator of lesser precedence.
                    currentOperator->parent = cursor1->parent;
                    currentOperator->parent->rchild = currentOperator;
                    cursor1->parent = currentOperator;
                    currentOperator->lchild = cursor1;
                    
                    // 4. Evaluate and pop all operators between prevOperator and cursor1.
                    ETNode * cursor2 = prevOperator;
                    while (cursor2 != cursor1)
                    {
                        prevOperator = prevOperator->parent;
                        cursor2->parent = nullptr;
                        prevOperator->rchild = nullptr;

                        // Evaluate and store the output of the converted literal and cursor2->lchild.
                        dynamic_cast<ETOperator*>(cursor2)->rchild = currentLeaf;
                        currentLeaf = _evalAndPopETOperator(dynamic_cast<ETOperator*>(cursor2));
                        if (currentLeaf)
                        {
                            // Apply any applicable unary operators to this result (operators placed on parentheses).
							while (!unaryBuffer.empty())
							{
								if (unaryBuffer.back().second >= prevOperator->priority)
								{
                                    currentLeaf = _applyUnaryOpAndPopETLeaf(currentLeaf, unaryBuffer.back().first);
									unaryBuffer.pop_back();
									if (!currentLeaf)
									{
										std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Unary operator failure in expression \""
											<< strExpr << "\"." << std::endl;

										// TODO: Test memory leaks in this scenario
										returnVal.first = false;
										return returnVal;
									}
								}
								else
									break;
							}
                        }
                        else
                        {
                            // TODO: Test memory leaks in this scenario
							returnVal.first = false;
							return returnVal;
                        }
                        cursor2 = prevOperator;
                    }

                    // Evaluate the last operator on the left.
                    prevOperator->rchild = currentLeaf;
                    prevOperator = prevOperator->parent;
                    prevOperator->lchild = _evalAndPopETOperator(dynamic_cast<ETOperator*>(cursor1));
                    if (prevOperator->lchild)
                    {
						// Apply any applicable unary operators to this result (operators placed on parentheses).
						while (!unaryBuffer.empty())
						{
							if (unaryBuffer.back().second >= prevOperator->priority)
							{
                                prevOperator->lchild = _applyUnaryOpAndPopETLeaf(prevOperator->lchild, unaryBuffer.back().first);
								unaryBuffer.pop_back();
								if (!prevOperator->lchild)
								{
									std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Unary operator failure in expression \""
										<< strExpr << "\"." << std::endl;

                                    // TODO: Test memory leaks in this scenario
									returnVal.first = false;
									return returnVal;
								}
							}
							else
								break;
						}
                        // Relink the new leaf into the tree. (might be unnecessary).
                        prevOperator->lchild->parent = prevOperator;
                    }
                    else
                    {
                        // TODO: Test memory leaks in this scenario
						returnVal.first = false;
						return returnVal;
                    }

                    currentLeaf = nullptr;
                    currentOperator = new ETOperator;
                }
            }
            else
            {
                // Abort
                std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Encountered unexpected non-operator \"" << token <<
                    "\" in expression \"" << strExpr << "\".  Confirm that a valid operator is present between all "
                    "literals." << std::endl;

                // BURN THEM ALL
                delete currentOperator;
                prevOperator->rchild = currentLeaf;
                _popETNode(root.rchild);

				returnVal.first = false;
				return returnVal;
            }
        }
    }
    
    // Finish up.

    // This should always be an empty stud by now.
	delete currentOperator;

	if (awaitingLiteral) // confirm we're not missing the final term.
	{
		std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Missing literal at end of expression \"" << strExpr <<
			"\".  Confirm that all operators have right operands." << std::endl;
		returnVal.first = false;
	}
	else
	{
		// Finish the tree.
		prevOperator->rchild = currentLeaf;

		// Detect unpaired parentheses
		if (currentPriority > 0)
		{
			std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Missing ')' before end of expression \""
				<< strExpr << "\".  Confirm that all '(' have a corresponding ')'." << std::endl;
			returnVal.first = false;
		}
		else
		{
            // What's left should be a valid tree, it just needs to be evaluated.

			currentOperator = prevOperator;
			while (prevOperator != &root)
			{
				prevOperator = prevOperator->parent;
                if ((currentLeaf = _evalAndPopETOperator(currentOperator)))
				{
					// Apply any applicable unary operators to this result (operators placed on parentheses).
					while (!unaryBuffer.empty())
					{
						if (unaryBuffer.back().second >= prevOperator->priority)
						{
                            currentLeaf = _applyUnaryOpAndPopETLeaf(currentLeaf, unaryBuffer.back().first);
							unaryBuffer.pop_back();
							if (!currentLeaf)
							{
								std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Unary operator failure in expression \""
									<< strExpr << "\"." << std::endl;

                                // TODO: Test memory leaks in this scenario
								returnVal.first = false;
								return returnVal;
							}
						}
						else
							break;
					}

                    if (!currentLeaf)
                    {
                        std::cout << "Hot Constants:  Arithmetic Evaluation Failure: Unary operator failure in expression \""
                            << strExpr << "\"." << std::endl;

                        // TODO: Test memory leaks in this scenario
                        returnVal.first = false;
                        return returnVal;
                    }
                    else
                    {
						prevOperator->rchild = currentLeaf;
						currentOperator = prevOperator;
					}
				}
				else
				{
                    // TODO: Test memory leaks in this scenario
					prevOperator->rchild = nullptr;
					returnVal.first = false;
					break;
				}
			}

			if (currentLeaf)
				returnVal.second = _castETLeaf<T>(root.rchild);
		}
	}

    // Destroy the tree.
    _popETNode(root.rchild);

    return returnVal;
}

}
