#pragma once
#include "HotConsts/HC_Enums.h"
#include <string>

namespace HotConsts
{

// Identifies a token as an arithmetic literal.  Assumes valid input, invalid identification is caught during conversion.
std::pair<literalType, literalBase> _identifyArithmeticLiteral(std::string& token);

// Identifies a token as an operator.
operationType _identifyOperator(std::string& token);

// Identifies a token as a unary operator.
unaryOperationType _identifyUnaryOperator(std::string& token);

// Integer type conversions
int				    _convertLiteralTo_int(std::string& token, literalBase base);
long				_convertLiteralTo_long(std::string& token, literalBase base);
long long			_convertLiteralTo_longlong(std::string& token, literalBase base);
unsigned int		_convertLiteralTo_uint(std::string& token, literalBase base);
unsigned long		_convertLiteralTo_ulong(std::string& token, literalBase base);
unsigned long long	_convertLiteralTo_ulonglong(std::string& token, literalBase base);

// Floating point type conversions
float				_convertLiteralTo_float(std::string& token, literalBase base);
double				_convertLiteralTo_double(std::string& token, literalBase base);
long double		    _convertLiteralTo_longdouble(std::string& token, literalBase base);

// Char type conversions
char				_convertLiteralTo_char(std::string& token);
char				_convertLiteralTo_char8(std::string& token); // c++17 TODO: Change to char8_t in c++20
char16_t			_convertLiteralTo_char16(std::string& token);
char32_t			_convertLiteralTo_char32(std::string& token);
wchar_t				_convertLiteralTo_wchar(std::string& token);
//int					_convertLiteralTo_multichar(std::string& token);

// Bool conversion
bool				_convertLiteralTo_bool(std::string& token);

}
