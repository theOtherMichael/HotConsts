#include "LiteralSamples.h"

using HotConsts::literalBase;
using HotConsts::literalType;
using HotConsts::operationType;

std::vector<std::string> intLiterals
{
	// Decimal
	"-1",
	"-123",

	// Octal
	"0123",

	// Hexadecimal
	"0x7F",
	"0X7F",

	// Binary
	"0b10101",
	"0B10101"
};

std::vector<std::string> longLiterals
{
	// Decimal
	"123l",
	"123L",

	// Octal
	"0123l",
	"0123L",

	// Hexadecimal
	"0x7Fl",
	"0x7FL",
	"0X7Fl",
	"0X7FL",

	// Binary
	"0b10101l",
	"0b10101L",
	"0B10101l",
	"0B10101L"
};

std::vector<std::string> longlongLiterals
{
	// Decimal
	"123ll",
	"123LL",

	// Octal
	"0123ll",
	"0123LL",

	// Hexadecimal
	"0x7Fll",
	"0x7FLL",
	"0X7Fll",
	"0X7FLL",

	// Binary
	"0b10101ll",
	"0b10101LL",
	"0B10101ll",
	"0B10101LL"
};

std::vector<std::string> uintLiterals
{
	// Decimal
	"123u",
	"123U",

	// Octal
	"0123u",
	"0123U",

	// Hexadecimal
	"0x7Fu",
	"0x7FU",
	"0X7Fu",
	"0X7FU",

	// Binary
	"0b10101u",
	"0b10101U",
	"0B10101u",
	"0B10101U"
};

std::vector<std::string> ulongLiterals
{
	// Decimal
	"123ul",
	"123Ul",
	"123uL",
	"123UL",
	"123lu",
	"123lU",
	"123Lu",
	"123LU",

	// Octal
	"0123ul",
	"0123Ul",
	"0123uL",
	"0123UL",
	"0123lu",
	"0123lU",
	"0123Lu",
	"0123LU",

	// Hexadecimal
	"0x7Ful",
	"0x7FUl",
	"0x7FuL",
	"0x7FUL",
	"0x7Flu",
	"0x7FlU",
	"0x7FLu",
	"0x7FLU",
	"0X7Ful",
	"0X7FUl",
	"0X7FuL",
	"0X7FUL",
	"0X7Flu",
	"0X7FlU",
	"0X7FLu",
	"0X7FLU",

	// Binary
	"0b10101ul",
	"0b10101Ul",
	"0b10101uL",
	"0b10101UL",
	"0b10101lu",
	"0b10101lU",
	"0b10101Lu",
	"0b10101LU",
	"0B10101ul",
	"0B10101Ul",
	"0B10101uL",
	"0B10101UL",
	"0B10101lu",
	"0B10101lU",
	"0B10101Lu",
	"0B10101LU"
};

std::vector<std::string> ulonglongLiterals
{
	// Decimal
	"123ull",
	"123Ull",
	"123uLL",
	"123ULL",
	"123llu",
	"123llU",
	"123LLu",
	"123LLU",

	// Octal
	"0123ull",
	"0123Ull",
	"0123uLL",
	"0123ULL",
	"0123llu",
	"0123llU",
	"0123LLu",
	"0123LLU",

	// Hexadecimal
	"0x7Full",
	"0x7FUll",
	"0x7FuLL",
	"0x7FULL",
	"0x7Fllu",
	"0x7FllU",
	"0x7FLLu",
	"0x7FLLU",
	"0X7Full",
	"0X7FUll",
	"0X7FuLL",
	"0X7FULL",
	"0X7Fllu",
	"0X7FllU",
	"0X7FLLu",
	"0X7FLLU",

	// Binary
	"0b10101ull",
	"0b10101Ull",
	"0b10101uLL",
	"0b10101ULL",
	"0b10101llu",
	"0b10101llU",
	"0b10101LLu",
	"0b10101LLU",
	"0B10101ull",
	"0B10101Ull",
	"0B10101uLL",
	"0B10101ULL",
	"0B10101llu",
	"0B10101llU",
	"0B10101LLu",
	"0B10101LLU"
};

std::vector<std::pair<literalType, literalBase>> intLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_int, literalBase::decimal), // "1"
	std::pair(literalType::lit_int, literalBase::decimal), // "123"

	// Octal
	std::pair(literalType::lit_int, literalBase::octal), // "0123"

	// Hexadecimal
	std::pair(literalType::lit_int, literalBase::hex), // "0x7F"
	std::pair(literalType::lit_int, literalBase::hex), // "0X7F"

	// Binary
	std::pair(literalType::lit_int, literalBase::binary), // "0b10101"
	std::pair(literalType::lit_int, literalBase::binary)  // "0B10101"
};

std::vector<std::pair<literalType, literalBase>> longLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_long, literalBase::decimal), // "123l"
	std::pair(literalType::lit_long, literalBase::decimal), // "123L"

	// Octal
	std::pair(literalType::lit_long, literalBase::octal), // "0123l"
	std::pair(literalType::lit_long, literalBase::octal), // "0123L"

	// Hexadecimal
	std::pair(literalType::lit_long, literalBase::hex), // "0x7Fl"
	std::pair(literalType::lit_long, literalBase::hex), // "0x7FL"
	std::pair(literalType::lit_long, literalBase::hex), // "0X7Fl"
	std::pair(literalType::lit_long, literalBase::hex), // "0X7FL"

	// Binary
	std::pair(literalType::lit_long, literalBase::binary), // "0b10101l"
	std::pair(literalType::lit_long, literalBase::binary), // "0b10101L"
	std::pair(literalType::lit_long, literalBase::binary), // "0B10101l"
	std::pair(literalType::lit_long, literalBase::binary)  // "0B10101L"
};

std::vector<std::pair<literalType, literalBase>> longlongLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_longlong, literalBase::decimal), // "123ll"
	std::pair(literalType::lit_longlong, literalBase::decimal), // "123LL"

	// Octal
	std::pair(literalType::lit_longlong, literalBase::octal), // "0123ll"
	std::pair(literalType::lit_longlong, literalBase::octal), // "0123LL"

	// Hexadecimal
	std::pair(literalType::lit_longlong, literalBase::hex), // "0x7Fll"
	std::pair(literalType::lit_longlong, literalBase::hex), // "0x7FLL"
	std::pair(literalType::lit_longlong, literalBase::hex), // "0X7Fll"
	std::pair(literalType::lit_longlong, literalBase::hex), // "0X7FLL"

	// Binary
	std::pair(literalType::lit_longlong, literalBase::binary), // "0b10101ll"
	std::pair(literalType::lit_longlong, literalBase::binary), // "0b10101LL"
	std::pair(literalType::lit_longlong, literalBase::binary), // "0B10101ll"
	std::pair(literalType::lit_longlong, literalBase::binary)  // "0B10101LL"
};

std::vector<std::pair<literalType, literalBase>> uintLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_uint, literalBase::decimal), // "123u"
	std::pair(literalType::lit_uint, literalBase::decimal), // "123U"

	// Octal
	std::pair(literalType::lit_uint, literalBase::octal), // "0123u"
	std::pair(literalType::lit_uint, literalBase::octal), // "0123U"

	// Hexadecimal
	std::pair(literalType::lit_uint, literalBase::hex), // "0x7Fu"
	std::pair(literalType::lit_uint, literalBase::hex), // "0x7FU"
	std::pair(literalType::lit_uint, literalBase::hex), // "0X7Fu"
	std::pair(literalType::lit_uint, literalBase::hex), // "0X7FU"

	// Binary
	std::pair(literalType::lit_uint, literalBase::binary), // "0b10101u"
	std::pair(literalType::lit_uint, literalBase::binary), // "0b10101U"
	std::pair(literalType::lit_uint, literalBase::binary), // "0B10101u"
	std::pair(literalType::lit_uint, literalBase::binary)  // "0B10101U"
};

std::vector<std::pair<literalType, literalBase>> ulongLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_ulong, literalBase::decimal), // "123ul"
	std::pair(literalType::lit_ulong, literalBase::decimal), // "123Ul"
	std::pair(literalType::lit_ulong, literalBase::decimal), // "123uL"
	std::pair(literalType::lit_ulong, literalBase::decimal), // "123UL"
	std::pair(literalType::lit_ulong, literalBase::decimal), // "123lu"
	std::pair(literalType::lit_ulong, literalBase::decimal), // "123lU"
	std::pair(literalType::lit_ulong, literalBase::decimal), // "123Lu"
	std::pair(literalType::lit_ulong, literalBase::decimal), // "123LU"

	// Octal
	std::pair(literalType::lit_ulong, literalBase::octal), // "0123ul"
	std::pair(literalType::lit_ulong, literalBase::octal), // "0123Ul"
	std::pair(literalType::lit_ulong, literalBase::octal), // "0123uL"
	std::pair(literalType::lit_ulong, literalBase::octal), // "0123UL"
	std::pair(literalType::lit_ulong, literalBase::octal), // "0123lu"
	std::pair(literalType::lit_ulong, literalBase::octal), // "0123lU"
	std::pair(literalType::lit_ulong, literalBase::octal), // "0123Lu"
	std::pair(literalType::lit_ulong, literalBase::octal), // "0123LU"

	// Hexadecimal
	std::pair(literalType::lit_ulong, literalBase::hex), // "0x7Ful"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0x7FUl"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0x7FuL"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0x7FUL"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0x7Flu"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0x7FlU"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0x7FLu"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0x7FLU"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0X7Ful"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0X7FUl"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0X7FuL"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0X7FUL"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0X7Flu"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0X7FlU"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0X7FLu"
	std::pair(literalType::lit_ulong, literalBase::hex), // "0X7FLU"

	// Binary
	std::pair(literalType::lit_ulong, literalBase::binary), // "0b10101ul"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0b10101Ul"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0b10101uL"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0b10101UL"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0b10101lu"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0b10101lU"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0b10101Lu"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0b10101LU"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0B10101ul"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0B10101Ul"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0B10101uL"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0B10101UL"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0B10101lu"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0B10101lU"
	std::pair(literalType::lit_ulong, literalBase::binary), // "0B10101Lu"
	std::pair(literalType::lit_ulong, literalBase::binary)  // "0B10101LU"
};

std::vector<std::pair<literalType, literalBase>> ulonglongLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_ulonglong, literalBase::decimal), // "123ull"
	std::pair(literalType::lit_ulonglong, literalBase::decimal), // "123Ull"
	std::pair(literalType::lit_ulonglong, literalBase::decimal), // "123uLL"
	std::pair(literalType::lit_ulonglong, literalBase::decimal), // "123ULL"
	std::pair(literalType::lit_ulonglong, literalBase::decimal), // "123llu"
	std::pair(literalType::lit_ulonglong, literalBase::decimal), // "123llU"
	std::pair(literalType::lit_ulonglong, literalBase::decimal), // "123LLu"
	std::pair(literalType::lit_ulonglong, literalBase::decimal), // "123LLU"

	// Octal
	std::pair(literalType::lit_ulonglong, literalBase::octal), // "0123ull"
	std::pair(literalType::lit_ulonglong, literalBase::octal), // "0123Ull"
	std::pair(literalType::lit_ulonglong, literalBase::octal), // "0123uLL"
	std::pair(literalType::lit_ulonglong, literalBase::octal), // "0123ULL"
	std::pair(literalType::lit_ulonglong, literalBase::octal), // "0123llu"
	std::pair(literalType::lit_ulonglong, literalBase::octal), // "0123llU"
	std::pair(literalType::lit_ulonglong, literalBase::octal), // "0123LLu"
	std::pair(literalType::lit_ulonglong, literalBase::octal), // "0123LLU"

	// Hexadecimal
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0x7Full"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0x7FUll"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0x7FuLL"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0x7FULL"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0x7Fllu"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0x7FllU"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0x7FLLu"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0x7FLLU"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0X7Full"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0X7FUll"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0X7FuLL"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0X7FULL"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0X7Fllu"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0X7FllU"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0X7FLLu"
	std::pair(literalType::lit_ulonglong, literalBase::hex), // "0X7FLLU"

	// Binary
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0b10101ull"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0b10101Ull"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0b10101uLL"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0b10101ULL"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0b10101llu"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0b10101llU"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0b10101LLu"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0b10101LLU"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0B10101ull"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0B10101Ull"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0B10101uLL"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0B10101ULL"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0B10101llu"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0B10101llU"
	std::pair(literalType::lit_ulonglong, literalBase::binary), // "0B10101LLu"
	std::pair(literalType::lit_ulonglong, literalBase::binary)  // "0B10101LLU"
};

std::vector<int> intLiteralConversions
{
	// Decimal
	-1,
	-123,

	// Octal
	0123,

	// Hexadecimal
	0x7F,
	0X7F,

	// Binary
	0b10101,
	0B10101
};

std::vector<long> longLiteralConversions
{
	// Decimal
	123l,
	123L,

	// Octal
	0123l,
	0123L,

	// Hexadecimal
	0x7Fl,
	0x7FL,
	0X7Fl,
	0X7FL,

	// Binary
	0b10101l,
	0b10101L,
	0B10101l,
	0B10101L
};

std::vector<long long> longlongLiteralConversions
{
	// Decimal
	123ll,
	123LL,

	// Octal
	0123ll,
	0123LL,

	// Hexadecimal
	0x7Fll,
	0x7FLL,
	0X7Fll,
	0X7FLL,

	// Binary
	0b10101ll,
	0b10101LL,
	0B10101ll,
	0B10101LL
};

std::vector<unsigned int> uintLiteralConversions
{
	// Decimal
	123u,
	123U,

	// Octal
	0123u,
	0123U,

	// Hexadecimal
	0x7Fu,
	0x7FU,
	0X7Fu,
	0X7FU,

	// Binary
	0b10101u,
	0b10101U,
	0B10101u,
	0B10101U
};

std::vector<unsigned long> ulongLiteralConversions
{
	// Decimal
	123ul,
	123Ul,
	123uL,
	123UL,
	123lu,
	123lU,
	123Lu,
	123LU,

	// Octal
	0123ul,
	0123Ul,
	0123uL,
	0123UL,
	0123lu,
	0123lU,
	0123Lu,
	0123LU,

	// Hexadecimal
	0x7Ful,
	0x7FUl,
	0x7FuL,
	0x7FUL,
	0x7Flu,
	0x7FlU,
	0x7FLu,
	0x7FLU,
	0X7Ful,
	0X7FUl,
	0X7FuL,
	0X7FUL,
	0X7Flu,
	0X7FlU,
	0X7FLu,
	0X7FLU,

	// Binary
	0b10101ul,
	0b10101Ul,
	0b10101uL,
	0b10101UL,
	0b10101lu,
	0b10101lU,
	0b10101Lu,
	0b10101LU,
	0B10101ul,
	0B10101Ul,
	0B10101uL,
	0B10101UL,
	0B10101lu,
	0B10101lU,
	0B10101Lu,
	0B10101LU
};

std::vector<unsigned long long> ulonglongLiteralConversions
{
	// Decimal
	123ull,
	123Ull,
	123uLL,
	123ULL,
	123llu,
	123llU,
	123LLu,
	123LLU,

	// Octal
	0123ull,
	0123Ull,
	0123uLL,
	0123ULL,
	0123llu,
	0123llU,
	0123LLu,
	0123LLU,

	// Hexadecimal
	0x7Full,
	0x7FUll,
	0x7FuLL,
	0x7FULL,
	0x7Fllu,
	0x7FllU,
	0x7FLLu,
	0x7FLLU,
	0X7Full,
	0X7FUll,
	0X7FuLL,
	0X7FULL,
	0X7Fllu,
	0X7FllU,
	0X7FLLu,
	0X7FLLU,

	// Binary
	0b10101ull,
	0b10101Ull,
	0b10101uLL,
	0b10101ULL,
	0b10101llu,
	0b10101llU,
	0b10101LLu,
	0b10101LLU,
	0B10101ull,
	0B10101Ull,
	0B10101uLL,
	0B10101ULL,
	0B10101llu,
	0B10101llU,
	0B10101LLu,
	0B10101LLU
};



std::vector<std::string> doubleLiterals
{
	// Decimal
	"123e1",
	"123E1",
	"123e-1",
	"123E-1",
	"123.",
	"123.e1",
	"123.E1",
	"123.e-1",
	"123.E-1",
	".123",
	".123e1",
	".123E1",
	".123e-1",
	".123E-1",
	"1.23",
	"1.23e1",
	"1.23E1",
	"1.23e-1",
	"1.23E-1",

	// Hexadecimal
	"0x7fp1",
	"0x7fP1",
	"0x7fp-1",
	"0x7fP-1",
	"0x7f.p1",
	"0x7f.P1",
	"0x7f.p-1",
	"0x7f.P-1",
	"0x.7fp1",
	"0x.7fP1",
	"0x.7fp-1",
	"0x.7fP-1",
	"0x7.fp1",
	"0x7.fP1",
	"0x7.fp-1",
	"0x7.fP-1",
	"0x7Fp1",
	"0x7FP1",
	"0x7Fp-1",
	"0x7FP-1",
	"0x7F.p1",
	"0x7F.P1",
	"0x7F.p-1",
	"0x7F.P-1",
	"0x.7Fp1",
	"0x.7FP1",
	"0x.7Fp-1",
	"0x.7FP-1",
	"0x7.Fp1",
	"0x7.FP1",
	"0x7.Fp-1",
	"0x7.FP-1"
};

std::vector<std::string> floatLiterals
{
	// Decimal
	"123e1f",
	"123E1f",
	"123e-1f",
	"123E-1f",
	"123.f",
	"123.e1f",
	"123.E1f",
	"123.e-1f",
	"123.E-1f",
	".123f",
	".123e1f",
	".123E1f",
	".123e-1f",
	".123E-1f",
	"1.23f",
	"1.23e1f",
	"1.23E1f",
	"1.23e-1f",
	"1.23E-1f",
	"123e1F",
	"123E1F",
	"123e-1F",
	"123E-1F",
	"123.F",
	"123.e1F",
	"123.E1F",
	"123.e-1F",
	"123.E-1F",
	".123F",
	".123e1F",
	".123E1F",
	".123e-1F",
	".123E-1F",
	"1.23F",
	"1.23e1F",
	"1.23E1F",
	"1.23e-1F",
	"1.23E-1F",

	// Hexadecimal
	"0x7fp1f",
	"0x7fP1f",
	"0x7fp-1f",
	"0x7fP-1f",
	"0x7f.p1f",
	"0x7f.P1f",
	"0x7f.p-1f",
	"0x7f.P-1f",
	"0x.7fp1f",
	"0x.7fP1f",
	"0x.7fp-1f",
	"0x.7fP-1f",
	"0x7.fp1f",
	"0x7.fP1f",
	"0x7.fp-1f",
	"0x7.fP-1f",
	"0x7fp7F",
	"0x7fP7F",
	"0x7fp-7F",
	"0x7fP-7F",
	"0x7f.p7F",
	"0x7f.P7F",
	"0x7f.p-7F",
	"0x7f.P-7F",
	"0x.7fp7F",
	"0x.7fP7F",
	"0x.7fp-7F",
	"0x.7fP-7F",
	"0x7.fp7F",
	"0x7.fP7F",
	"0x7.fp-7F",
	"0x7.fP-7F",
	"0x7Fp1f",
	"0x7FP1f",
	"0x7Fp-1f",
	"0x7FP-1f",
	"0x7F.p1f",
	"0x7F.P1f",
	"0x7F.p-1f",
	"0x7F.P-1f",
	"0x.7Fp1f",
	"0x.7FP1f",
	"0x.7Fp-1f",
	"0x.7FP-1f",
	"0x7.Fp1f",
	"0x7.FP1f",
	"0x7.Fp-1f",
	"0x7.FP-1f",
	"0x7Fp7F",
	"0x7FP7F",
	"0x7Fp-7F",
	"0x7FP-7F",
	"0x7F.p7F",
	"0x7F.P7F",
	"0x7F.p-7F",
	"0x7F.P-7F",
	"0x.7Fp7F",
	"0x.7FP7F",
	"0x.7Fp-7F",
	"0x.7FP-7F",
	"0x7.Fp7F",
	"0x7.FP7F",
	"0x7.Fp-7F",
	"0x7.FP-7F"
};

std::vector<std::string> longDoubleLiterals
{
	// Decimal
	"123e1l",
	"123E1l",
	"123e-1l",
	"123E-1l",
	"123.l",
	"123.e1l",
	"123.E1l",
	"123.e-1l",
	"123.E-1l",
	".123l",
	".123e1l",
	".123E1l",
	".123e-1l",
	".123E-1l",
	"1.23l",
	"1.23e1l",
	"1.23E1l",
	"1.23e-1l",
	"1.23E-1l",
	"123e1L",
	"123E1L",
	"123e-1L",
	"123E-1L",
	"123.L",
	"123.e1L",
	"123.E1L",
	"123.e-1L",
	"123.E-1L",
	".123L",
	".123e1L",
	".123E1L",
	".123e-1L",
	".123E-1L",
	"1.23L",
	"1.23e1L",
	"1.23E1L",
	"1.23e-1L",
	"1.23E-1L",

	// Hexadecimal
	"0x7fp1l",
	"0x7fP1l",
	"0x7fp-1l",
	"0x7fP-1l",
	"0x7f.p1l",
	"0x7f.P1l",
	"0x7f.p-1l",
	"0x7f.P-1l",
	"0x.7fp1l",
	"0x.7fP1l",
	"0x.7fp-1l",
	"0x.7fP-1l",
	"0x7.fp1l",
	"0x7.fP1l",
	"0x7.fp-1l",
	"0x7.fP-1l",
	"0x7fp1L",
	"0x7fP1L",
	"0x7fp-1L",
	"0x7fP-1L",
	"0x7f.p1L",
	"0x7f.P1L",
	"0x7f.p-1L",
	"0x7f.P-1L",
	"0x.7fp1L",
	"0x.7fP1L",
	"0x.7fp-1L",
	"0x.7fP-1L",
	"0x7.fp1L",
	"0x7.fP1L",
	"0x7.fp-1L",
	"0x7.fP-1L",
	"0x7Fp1l",
	"0x7FP1l",
	"0x7Fp-1l",
	"0x7FP-1l",
	"0x7F.p1l",
	"0x7F.P1l",
	"0x7F.p-1l",
	"0x7F.P-1l",
	"0x.7Fp1l",
	"0x.7FP1l",
	"0x.7Fp-1l",
	"0x.7FP-1l",
	"0x7.Fp1l",
	"0x7.FP1l",
	"0x7.Fp-1l",
	"0x7.FP-1l",
	"0x7Fp1L",
	"0x7FP1L",
	"0x7Fp-1L",
	"0x7FP-1L",
	"0x7F.p1L",
	"0x7F.P1L",
	"0x7F.p-1L",
	"0x7F.P-1L",
	"0x.7Fp1L",
	"0x.7FP1L",
	"0x.7Fp-1L",
	"0x.7FP-1L",
	"0x7.Fp1L",
	"0x7.FP1L",
	"0x7.Fp-1L",
	"0x7.FP-1L"
};

std::vector<std::pair<literalType, literalBase>> doubleLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_double, literalBase::decimal), // "123e1",
	std::pair(literalType::lit_double, literalBase::decimal), // "123E1",
	std::pair(literalType::lit_double, literalBase::decimal), // "123e-1",
	std::pair(literalType::lit_double, literalBase::decimal), // "123E-1",
	std::pair(literalType::lit_double, literalBase::decimal), // "123.",
	std::pair(literalType::lit_double, literalBase::decimal), // "123.e1",
	std::pair(literalType::lit_double, literalBase::decimal), // "123.E1",
	std::pair(literalType::lit_double, literalBase::decimal), // "123.e-1",
	std::pair(literalType::lit_double, literalBase::decimal), // "123.E-1",
	std::pair(literalType::lit_double, literalBase::decimal), // ".123",
	std::pair(literalType::lit_double, literalBase::decimal), // ".123e1",
	std::pair(literalType::lit_double, literalBase::decimal), // ".123E1",
	std::pair(literalType::lit_double, literalBase::decimal), // ".123e-1",
	std::pair(literalType::lit_double, literalBase::decimal), // ".123E-1",
	std::pair(literalType::lit_double, literalBase::decimal), // "1.23",
	std::pair(literalType::lit_double, literalBase::decimal), // "1.23e1",
	std::pair(literalType::lit_double, literalBase::decimal), // "1.23E1",
	std::pair(literalType::lit_double, literalBase::decimal), // "1.23e-1",
	std::pair(literalType::lit_double, literalBase::decimal), // "1.23E-1",

	// Hexadecimal
	std::pair(literalType::lit_double, literalBase::hex), // "0x7fp1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7fP1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7fp-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7fP-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7f.p1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7f.P1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7f.p-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7f.P-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x.7fp1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x.7fP1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x.7fp-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x.7fP-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7.fp1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7.fP1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7.fp-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7.fP-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7Fp1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7FP1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7Fp-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7FP-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7F.p1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7F.P1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7F.p-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7F.P-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x.7Fp1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x.7FP1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x.7Fp-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x.7FP-1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7.Fp1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7.FP1",
	std::pair(literalType::lit_double, literalBase::hex), // "0x7.Fp-1",
	std::pair(literalType::lit_double, literalBase::hex)  // "0x7.FP-1",
};

std::vector<std::pair<literalType, literalBase>> floatLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_float, literalBase::decimal), // "123e1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123E1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123e-1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123E-1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.e1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.E1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.e-1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.E-1f",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123f",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123e1f",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123E1f",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123e-1f",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123E-1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23f",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23e1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23E1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23e-1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23E-1f",
	std::pair(literalType::lit_float, literalBase::decimal), // "123e1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "123E1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "123e-1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "123E-1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.F",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.e1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.E1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.e-1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "123.E-1F",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123F",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123e1F",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123E1F",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123e-1F",
	std::pair(literalType::lit_float, literalBase::decimal), // ".123E-1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23F",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23e1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23E1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23e-1F",
	std::pair(literalType::lit_float, literalBase::decimal), // "1.23E-1F",

	// Hexadecimal
	std::pair(literalType::lit_float, literalBase::hex), // "0x7fp1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7fP1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7fp-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7fP-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7f.p1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7f.P1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7f.p-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7f.P-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7fp1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7fP1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7fp-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7fP-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.fp1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.fP1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.fp-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.fP-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7fp7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7fP7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7fp-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7fP-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7f.p7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7f.P7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7f.p-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7f.P-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7fp7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7fP7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7fp-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7fP-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.fp7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.fP7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.fp-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.fP-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7Fp1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7FP1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7Fp-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7FP-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7F.p1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7F.P1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7F.p-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7F.P-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7Fp1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7FP1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7Fp-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7FP-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.Fp1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.FP1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.Fp-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.FP-1f",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7Fp7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7FP7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7Fp-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7FP-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7F.p7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7F.P7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7F.p-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7F.P-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7Fp7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7FP7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7Fp-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x.7FP-7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.Fp7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.FP7F",
	std::pair(literalType::lit_float, literalBase::hex), // "0x7.Fp-7F",
	std::pair(literalType::lit_float, literalBase::hex) // "0x7.FP-7F",
};

std::vector<std::pair<literalType, literalBase>> longDoubleLiteralIdentities
{
	// Decimal
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123e1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123E1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123e-1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123E-1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.e1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.E1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.e-1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.E-1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123e1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123E1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123e-1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123E-1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23e1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23E1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23e-1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23E-1l",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123e1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123E1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123e-1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123E-1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.e1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.E1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.e-1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "123.E-1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123e1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123E1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123e-1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // ".123E-1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23e1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23E1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23e-1L",
	std::pair(literalType::lit_longdouble, literalBase::decimal), // "1.23E-1L",

	// Hexadecimal
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7fp1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7fP1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7fp-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7fP-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7f.p1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7f.P1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7f.p-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7f.P-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7fp1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7fP1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7fp-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7fP-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.fp1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.fP1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.fp-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.fP-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7fp1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7fP1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7fp-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7fP-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7f.p1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7f.P1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7f.p-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7f.P-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7fp1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7fP1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7fp-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7fP-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.fp1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.fP1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.fp-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.fP-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7Fp1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7FP1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7Fp-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7FP-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7F.p1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7F.P1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7F.p-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7F.P-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7Fp1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7FP1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7Fp-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7FP-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.Fp1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.FP1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.Fp-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.FP-1l",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7Fp1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7FP1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7Fp-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7FP-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7F.p1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7F.P1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7F.p-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7F.P-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7Fp1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7FP1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7Fp-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x.7FP-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.Fp1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.FP1L",
	std::pair(literalType::lit_longdouble, literalBase::hex), // "0x7.Fp-1L",
	std::pair(literalType::lit_longdouble, literalBase::hex)  // "0x7.FP-1L",
};

std::vector<double> doubleLiteralConversions
{
	// Decimal
	123e1,
	123E1,
	123e-1,
	123E-1,
	123.,
	123.e1,
	123.E1,
	123.e-1,
	123.E-1,
	.123,
	.123e1,
	.123E1,
	.123e-1,
	.123E-1,
	1.23,
	1.23e1,
	1.23E1,
	1.23e-1,
	1.23E-1,

	// Hexadecimal
	0x7fp1,
	0x7fP1,
	0x7fp-1,
	0x7fP-1,
	0x7f.p1,
	0x7f.P1,
	0x7f.p-1,
	0x7f.P-1,
	0x.7fp1,
	0x.7fP1,
	0x.7fp-1,
	0x.7fP-1,
	0x7.fp1,
	0x7.fP1,
	0x7.fp-1,
	0x7.fP-1,
	0x7Fp1,
	0x7FP1,
	0x7Fp-1,
	0x7FP-1,
	0x7F.p1,
	0x7F.P1,
	0x7F.p-1,
	0x7F.P-1,
	0x.7Fp1,
	0x.7FP1,
	0x.7Fp-1,
	0x.7FP-1,
	0x7.Fp1,
	0x7.FP1,
	0x7.Fp-1,
	0x7.FP-1
};

std::vector<float> floatLiteralConversions
{
	// Decimal
	123e1f,
	123E1f,
	123e-1f,
	123E-1f,
	123.f,
	123.e1f,
	123.E1f,
	123.e-1f,
	123.E-1f,
	.123f,
	.123e1f,
	.123E1f,
	.123e-1f,
	.123E-1f,
	1.23f,
	1.23e1f,
	1.23E1f,
	1.23e-1f,
	1.23E-1f,
	123e1F,
	123E1F,
	123e-1F,
	123E-1F,
	123.F,
	123.e1F,
	123.E1F,
	123.e-1F,
	123.E-1F,
	.123F,
	.123e1F,
	.123E1F,
	.123e-1F,
	.123E-1F,
	1.23F,
	1.23e1F,
	1.23E1F,
	1.23e-1F,
	1.23E-1F,

	// Hexadecimal
	0x7fp1f,
	0x7fP1f,
	0x7fp-1f,
	0x7fP-1f,
	0x7f.p1f,
	0x7f.P1f,
	0x7f.p-1f,
	0x7f.P-1f,
	0x.7fp1f,
	0x.7fP1f,
	0x.7fp-1f,
	0x.7fP-1f,
	0x7.fp1f,
	0x7.fP1f,
	0x7.fp-1f,
	0x7.fP-1f,
	0x7fp7F,
	0x7fP7F,
	0x7fp-7F,
	0x7fP-7F,
	0x7f.p7F,
	0x7f.P7F,
	0x7f.p-7F,
	0x7f.P-7F,
	0x.7fp7F,
	0x.7fP7F,
	0x.7fp-7F,
	0x.7fP-7F,
	0x7.fp7F,
	0x7.fP7F,
	0x7.fp-7F,
	0x7.fP-7F,
	0x7Fp1f,
	0x7FP1f,
	0x7Fp-1f,
	0x7FP-1f,
	0x7F.p1f,
	0x7F.P1f,
	0x7F.p-1f,
	0x7F.P-1f,
	0x.7Fp1f,
	0x.7FP1f,
	0x.7Fp-1f,
	0x.7FP-1f,
	0x7.Fp1f,
	0x7.FP1f,
	0x7.Fp-1f,
	0x7.FP-1f,
	0x7Fp7F,
	0x7FP7F,
	0x7Fp-7F,
	0x7FP-7F,
	0x7F.p7F,
	0x7F.P7F,
	0x7F.p-7F,
	0x7F.P-7F,
	0x.7Fp7F,
	0x.7FP7F,
	0x.7Fp-7F,
	0x.7FP-7F,
	0x7.Fp7F,
	0x7.FP7F,
	0x7.Fp-7F,
	0x7.FP-7F
};

std::vector<long double> longDoubleLiteralConversions
{
	// Decimal
	123e1l,
	123E1l,
	123e-1l,
	123E-1l,
	123.l,
	123.e1l,
	123.E1l,
	123.e-1l,
	123.E-1l,
	.123l,
	.123e1l,
	.123E1l,
	.123e-1l,
	.123E-1l,
	1.23l,
	1.23e1l,
	1.23E1l,
	1.23e-1l,
	1.23E-1l,
	123e1L,
	123E1L,
	123e-1L,
	123E-1L,
	123.L,
	123.e1L,
	123.E1L,
	123.e-1L,
	123.E-1L,
	.123L,
	.123e1L,
	.123E1L,
	.123e-1L,
	.123E-1L,
	1.23L,
	1.23e1L,
	1.23E1L,
	1.23e-1L,
	1.23E-1L,

	// Hexadecimal
	0x7fp1l,
	0x7fP1l,
	0x7fp-1l,
	0x7fP-1l,
	0x7f.p1l,
	0x7f.P1l,
	0x7f.p-1l,
	0x7f.P-1l,
	0x.7fp1l,
	0x.7fP1l,
	0x.7fp-1l,
	0x.7fP-1l,
	0x7.fp1l,
	0x7.fP1l,
	0x7.fp-1l,
	0x7.fP-1l,
	0x7fp1L,
	0x7fP1L,
	0x7fp-1L,
	0x7fP-1L,
	0x7f.p1L,
	0x7f.P1L,
	0x7f.p-1L,
	0x7f.P-1L,
	0x.7fp1L,
	0x.7fP1L,
	0x.7fp-1L,
	0x.7fP-1L,
	0x7.fp1L,
	0x7.fP1L,
	0x7.fp-1L,
	0x7.fP-1L,
	0x7Fp1l,
	0x7FP1l,
	0x7Fp-1l,
	0x7FP-1l,
	0x7F.p1l,
	0x7F.P1l,
	0x7F.p-1l,
	0x7F.P-1l,
	0x.7Fp1l,
	0x.7FP1l,
	0x.7Fp-1l,
	0x.7FP-1l,
	0x7.Fp1l,
	0x7.FP1l,
	0x7.Fp-1l,
	0x7.FP-1l,
	0x7Fp1L,
	0x7FP1L,
	0x7Fp-1L,
	0x7FP-1L,
	0x7F.p1L,
	0x7F.P1L,
	0x7F.p-1L,
	0x7F.P-1L,
	0x.7Fp1L,
	0x.7FP1L,
	0x.7Fp-1L,
	0x.7FP-1L,
	0x7.Fp1L,
	0x7.FP1L,
	0x7.Fp-1L,
	0x7.FP-1L
};


std::vector<std::string> charLiterals
{
	// Trivial characters

	"'c'",
	//"u8'c'", //c++20
	"u'c'",
	"U'c'",
	"L'c'",

	// Escape sequences

	// char
	"'\\''",
	"'\\\"'",
	"'\\?'",
	"'\\\\'",
	"'\\a'",
	"'\\b'",
	"'\\f'",
	"'\\n'",
	"'\\r'",
	"'\\t'",
	"'\\v'",
	"'\\377'",				//octal (max three digits)
	"'\\77'",				//octal
	"'\\7'",				//octal
	"'\\xFF'",				//hex (no max)
	"'\\xF'",				//hex
	"'\\u0040'",			//unicode
	"'\\U00000040'",		//unicode
					
	// utf-8 (c++20)
	//"u8'\\''",
	//"u8'\\\"'",
	//"u8'\\?'",
	//"u8'\\\\'",
	//"u8'\\a'",
	//"u8'\\b'",
	//"u8'\\f'",
	//"u8'\\n'",
	//"u8'\\r'",
	//"u8'\\t'",
	//"u8'\\v'",
	//"u8'\\377'",			//octal (max three digits)
	//"u8'\\77'",			//octal
	//"u8'\\7'",			//octal
	//"u8'\\xFF'",			//hex (no max)
	//"u8'\\xF'",			//hex
	//"u8'\\u0040'",		//unicode
	//"u8'\\U00000040'",	//unicode

	// utf-16
	"u'\\''",
	"u'\\\"'",
	"u'\\?'",
	"u'\\\\'",
	"u'\\a'",
	"u'\\b'",
	"u'\\f'",
	"u'\\n'",
	"u'\\r'",
	"u'\\t'",
	"u'\\v'",
	"u'\\377'",			//octal (max three digits)
	"u'\\77'",			//octal
	"u'\\7'",			//octal
	"u'\\xFF'",			//hex (no max)
	"u'\\xF'",			//hex
	"u'\\u0040'",		//unicode
	"u'\\U00000040'",	//unicode

	// utf-32
	"U'\\''",
	"U'\\\"'",
	"U'\\?'",
	"U'\\\\'",
	"U'\\a'",
	"U'\\b'",
	"U'\\f'",
	"U'\\n'",
	"U'\\r'",
	"U'\\t'",
	"U'\\v'",
	"U'\\377'",			//octal (max three digits)
	"U'\\77'",			//octal
	"U'\\7'",			//octal
	"U'\\xFF'",			//hex (no max)
	"U'\\xF'",			//hex
	"U'\\u0040'",		//unicode
	"U'\\U00000040'",	//unicode

	// wide char
	"L'\\''",
	"L'\\\"'",
	"L'\\?'",
	"L'\\\\'",
	"L'\\a'",
	"L'\\b'",
	"L'\\f'",
	"L'\\n'",
	"L'\\r'",
	"L'\\t'",
	"L'\\v'",
	"L'\\377'",			//octal (max three digits)
	"L'\\77'",			//octal
	"L'\\7'",			//octal
	"L'\\xFF'",			//hex (no max)
	"L'\\xF'",			//hex
	"L'\\u0040'",		//unicode
	"L'\\U00000040'"	//unicode
};

std::vector<std::pair<literalType, literalBase>> charLiteralIdentities
{
	// Trivial characters

	std::pair(literalType::lit_char, literalBase::notapplicable), // "'c'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'c'", //c++20
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'c'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'c'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'c'",

	// Escape sequences

	// char
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\''",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\\"'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\?'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\\\'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\a'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\b'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\f'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\n'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\r'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\t'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\v'",
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\377'",			//octal (max three digits)
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\77'",			//octal
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\7'",			//octal
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\xFF'",			//hex (no max)
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\xF'",			//hex
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\u0040'",		//unicode
	std::pair(literalType::lit_char, literalBase::notapplicable), // "'\\U00000040'",	//unicode

	// utf-8 (c++20)
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\''",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\\"'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\?'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\\\'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\a'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\b'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\f'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\n'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\r'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\t'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\v'",
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\377'",		//octal (max three digits)
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\77'",			//octal
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\7'",			//octal
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\xFF'",		//hex (no max)
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\xF'",			//hex
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\u0040'",		//unicode
	//std::pair(literalType::lit_char8, literalBase::notapplicable), // "u8'\\U00000040'",	//unicode

	// utf-16
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\''",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\\"'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\?'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\\\'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\a'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\b'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\f'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\n'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\r'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\t'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\v'",
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\377'",			//octal (max three digits)
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\77'",			//octal
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\7'",			//octal
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\xFF'",			//hex (no max)
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\xF'",			//hex
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\u0040'",		//unicode
	std::pair(literalType::lit_char16, literalBase::notapplicable), // "u'\\U00000040'",	//unicode

	// utf-32
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\''",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\\"'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\?'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\\\'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\a'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\b'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\f'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\n'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\r'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\t'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\v'",
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\377'",			//octal (max three digits)
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\77'",			//octal
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\7'",			//octal
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\xFF'",			//hex (no max)
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\xF'",			//hex
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\u0040'",		//unicode
	std::pair(literalType::lit_char32, literalBase::notapplicable), // "U'\\U00000040'",	//unicode

	// wide char
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\''",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\\"'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\?'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\\\'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\a'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\b'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\f'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\n'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\r'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\t'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\v'",
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\377'",			//octal (max three digits)
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\77'",			//octal
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\7'",				//octal
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\xFF'",			//hex (no max)
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\xF'",			//hex
	std::pair(literalType::lit_wchar, literalBase::notapplicable), // "L'\\u0040'",			//unicode
	std::pair(literalType::lit_wchar, literalBase::notapplicable)  // "L'\\U00000040'"		//unicode
};


std::vector<std::string> operatorTokens
{
	"*",
	"/",
	"%",
	
	"+",
	"-",
	
	"<<",
	">>",
	
	//"<=>", //c++20
	
	"<",
	"<=",
	">",
	">=",
	
	"==",
	"!=",

	"&",
	"^",
	"|",

	"&&",
	"||"
};

std::vector<operationType> operatorIdentities
{
	operationType::multiply,
	operationType::divide,
	operationType::modulo,

	operationType::add,
	operationType::subtract,

	operationType::bitshift_left,
	operationType::bitshift_right,

	//operationType::compare_threeway, //c++20

	operationType::compare_lt,
	operationType::compare_ltoreq,
	operationType::compare_gt,
	operationType::compare_gtoreq,

	operationType::compare_eq,
	operationType::compare_neq,

	operationType::bitwise_AND,

	operationType::bitwise_XOR,

	operationType::bitwise_OR,

	operationType::logical_AND,

	operationType::logical_OR
};


std::vector<std::string> stringLiterals
{
	// Strings
	"\"This is a string.\"",
	"u8\"This is a UTF-8 string.\"",
	"u\"This is a UTF-16 string.\"",
	"U\"This is a UTF-32 string.\"",
	"L\"This is a wide string.\"",

	// Raw strings
	"R\"(This is\\na test\\nraw string\\n)\"",
	"R\"abcd-12&34!#-_[}(This is\\na test\\nraw string\\n)abcd-12&34!#-_[}\"",
	"u8R\"(This is\\na test\\nraw UTF-8 string\\n)\"",
	"u8R\"abcd-12&34!#-_[}(This is\\na test\\nraw UTF-8 string\\n)abcd-12&34!#-_[}\"",
	"uR\"(This is\\na test\\nraw UTF-16 string\\n)\"",
	"uR\"abcd-12&34!#-_[}(This is\\na test\\nraw UTF-16 string\\n)abcd-12&34!#-_[}\"",
	"UR\"(This is\\na test\\nraw UTF-32 string\\n)\"",
	"UR\"abcd-12&34!#-_[}(This is\\na test\\nraw UTF-32 string\\n)abcd-12&34!#-_[}\"",
	"LR\"(This is\\na test\\nraw wide string\\n)\"",
	"LR\"abcd-12&34!#-_[}(This is\\na test\\nraw wide string\\n)abcd-12&34!#-_[}\"",

	// STD strings
	"\"This is a test std::string.\"s",
	"u8\"This is a test std::u8string.\"s",
	"u\"This is a test std::u16string.\"s",
	"U\"This is a test std::u32string.\"s",
	"L\"This is a test std::wstring.\"s"
};
