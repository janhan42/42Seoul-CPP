#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

/* Public Functions */
void	ScalarConverter::convert(const std::string &literal)
{
	mLiteral = literal;
}

void	ScalarConverter::PrintChar(void)
{
	std::cout << "char: ";
	if (isChar())
	{
		if ((0 <= static_cast<int>(mLiteral[1]))
			&& std::iscntrl(static_cast<int>(mLiteral[1])) == false)
		{
			std::cout << '\'' << mLiteral[1] << '\'' << std::endl;
		}
		else
		{
			std::cout << "inpossible" << std::endl;
		}
	}
	else if (isInt())
	{
		long longValue = std::strtol(mLiteral.c_str(), NULL, 10);
		int intValue = static_cast<int>(longValue);
		if (static_cast<int>(std::numeric_limits<char>::min()) <= intValue
		&& intValue <= static_cast<int>(std::numeric_limits<char>::max()))
		{
			if (iscntrl(intValue) == false
			&& (0<= intValue && intValue < 128))
			{
				std::cout << '\'' << static_cast<char>(intValue) << '\'' << std::endl;
			}
			else
			{
				std::cout << "Non displable" << std::endl;
			}
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else if (isFloat())
	{
		double doubleValue = std::strtod(mLiteral.c_str(), NULL);
		float	floatValue = static_cast<float>(doubleValue);
		if (static_cast<float>(std::numeric_limits<char>::min() <= floatValue
		&& floatValue <= static_cast<float>(std::numeric_limits<char>::max())))
		{
			if ((0.0f <= floatValue && floatValue < 128.0f)
				&& iscntrl(static_cast<int>(floatValue)) == false)
			{
				std::cout << '\'' << static_cast<char>(floatValue) << '\'' << std::endl;
			}
			else
			{
				std::cout << "Non displayable" << std::endl;
			}
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else if (isDouble())
	{

	}
}

/* Private */
bool	ScalarConverter::isChar(void)
{
	if (mLiteral.length() == 3
		&& mLiteral[0] == '\''
		&& mLiteral[2] == '\'')
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	mLiteral을 .c_str로 const char*에 담아두고
	std::strtol을 사용해서 문자열을 정수로 변환.
	long std::strtol(const char* str, char** endptr, int base);

	매개 변수
	- 'str': 변환할 문자열을 가리키는 포인터
	- 'endptr': 변환이 완료된 후 문자열의 나머지를 가리키는 포인터를 저장할 변수의 주소, 이 포인터는
	nullptr일 수 있습니다.
	- 'base': 문자열 해석의 기준이 되는 진법입니다.
 */
bool	ScalarConverter::isInt(void)
{
	char* endPtr = NULL;
	const char* cStr = mLiteral.c_str();
	long	longInt = std::strtol(cStr, &endPtr, 10);
	if (mLiteral.length() != 0
		&& *endPtr == '\0'
		&& (static_cast<long>(std::numeric_limits<int>::min()) <= longInt
		&& longInt <= static_cast<long>(std::numeric_limits<int>::max())))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool	ScalarConverter::isFloat(void)
{
	if (mLiteral == std::string("-inff") || mLiteral == std::string("+inff") || mLiteral == std::string("nanf"))
		return true;
	char* endPtr = NULL;
	const char* cStr = mLiteral.c_str();
	double	doubleValue = std::strtod(cStr, &endPtr);
	size_t	dotCount = 0;
	for (size_t i = 0; cStr[i]; ++i)
	{
		if (cStr[i] == '.')
		{
			++dotCount;
		}
	}
	if (dotCount != 1)
	{
		return false;
	}
	if (mLiteral.length() >= 3
	&& endPtr != NULL
	&& endPtr[0] == 'f'
	&& endPtr[1] == '\0'
	&& (-static_cast<double>(std::numeric_limits<float>::max()) <= doubleValue
	&& doubleValue <= static_cast<double>(std::numeric_limits<float>::max())))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool	ScalarConverter::isDouble(void)
{
	if (mLiteral == std::string("nan") || mLiteral == std::string("+inf") || mLiteral == std::string("-inf"))
		return true;
	char* endPtr = NULL;
	const char* cStr = mLiteral.c_str();
	double doubleValue = std::strtod(cStr, &endPtr);
	if (mLiteral.length() >= 2
	&& endPtr != NULL
	&& *endPtr == '\0'
	&& (-std::numeric_limits<double>::max() <= doubleValue
	&& doubleValue <= std::numeric_limits<double>::max()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	(void)rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return (*this);
}
