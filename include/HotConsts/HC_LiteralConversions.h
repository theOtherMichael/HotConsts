#pragma once
#include "HC_PCH.h"
#include "HC_Enums.h"

namespace HotConsts
{

// Identifies a token as an arithmetic literal.  Assumes valid input, invalid identification is caught during conversion.
std::pair<literalType, literalBase> _identifyArithmeticLiteral(std::string& token);

// Identifies a token as an operator.
operationType _identifyOperator(std::string& token);

// Identifies a token as a unary operator.
unaryOperationType _identifyUnaryOperator(std::string& token);


// Integer type conversions

std::pair<bool, int>				_convertLiteralTo_int(std::string& token, literalBase base);
std::pair<bool, long>				_convertLiteralTo_long(std::string& token, literalBase base);
std::pair<bool, long long>			_convertLiteralTo_longlong(std::string& token, literalBase base);
std::pair<bool, unsigned int>		_convertLiteralTo_uint(std::string& token, literalBase base);
std::pair<bool, unsigned long>		_convertLiteralTo_ulong(std::string& token, literalBase base);
std::pair<bool, unsigned long long>	_convertLiteralTo_ulonglong(std::string& token, literalBase base);

// Floating point type conversions

std::pair<bool, float>				_convertLiteralTo_float(std::string& token, literalBase base);
std::pair<bool, double>				_convertLiteralTo_double(std::string& token, literalBase base);
std::pair<bool, long double>		_convertLiteralTo_longdouble(std::string& token, literalBase base);

// Char type conversions

std::pair<bool, char>				_convertLiteralTo_char(std::string& token);
//std::pair<bool, char8_t>			convertLiteralTo_char8(std::string& token); // c++20
std::pair<bool, char16_t>			_convertLiteralTo_char16(std::string& token);
std::pair<bool, char32_t>			_convertLiteralTo_char32(std::string& token);
std::pair<bool, wchar_t>			_convertLiteralTo_wchar(std::string& token);

// Bool conversion

std::pair<bool, bool>				_convertLiteralTo_bool(std::string& token);

// String conversions
// TODO: declare string conversion functions


}
