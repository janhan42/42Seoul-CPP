/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:37:57 by janhan            #+#    #+#             */
/*   Updated: 2024/08/29 16:02:26 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cstdlib>

bool	isChar(const std::string& literal);
bool	isInt(const std::string& literal);
bool	isFloat(const std::string& literal);
bool	isDouble(const std::string& literal);
void	convertToChar(const std::string& literal);
void	convertToInt(const std::string& literal);
void	convertToFloat(const std::string& literal);
void	convertToDouble(const std::string& literal);

/* public */
void	ScalarConverter::convert(const std::string &literal)
{
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}

void	convertToChar(const std::string& literal)
{
	std::cout << "char: ";
	if (isChar(literal))
	{
		if ((0 <= static_cast<int>(literal[1]))
		&& std::iscntrl(static_cast<int>(literal[1])) == false)
		{
			std::cout << '\'' << literal[1] << '\'' << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else if (isInt(literal))
	{
		long longValue = std::strtol(literal.c_str(), NULL, 10);
		int	intValue = static_cast<int>(longValue);
		if (static_cast<int>(std::numeric_limits<char>::min()) <= longValue
		&& longValue <= static_cast<int>(std::numeric_limits<char>::max()))
		{
			if (iscntrl(intValue) == false
			&& (0 <= intValue && intValue < 128))
			{
				std::cout << '\'' << static_cast<char>(intValue) << '\'' << std::endl;
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
	else if (isFloat(literal))
	{
		double doubleValue = std::strtod(literal.c_str(), NULL);
		float floatValue = static_cast<float>(doubleValue);
		if (static_cast<float>(std::numeric_limits<char>::min()) <= floatValue
		&& floatValue <= static_cast<float>(std::numeric_limits<char>::max()))
		{
			if ((0.0f <= floatValue && floatValue <= 128.0f)
			&&	iscntrl(static_cast<int>(floatValue)) == false)
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
	else if (isDouble(literal))
	{
		double doubleValue = std::strtod(literal.c_str(), NULL);
		if (static_cast<double>(std::numeric_limits<char>::min() <= doubleValue
		&& doubleValue <= static_cast<double>(std::numeric_limits<char>::max())))
		{
			if (0.0 <= doubleValue && doubleValue < 128
			&& iscntrl(static_cast<int>(doubleValue)) == false)
			{
				std::cout << '\'' << static_cast<char>(doubleValue) << '\'' << std::endl;
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
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	convertToInt(const std::string& literal)
{
	std::cout << "int: ";
	if (isChar(literal))
	{
		std::cout << static_cast<int>(literal[1]) << std::endl;
	}
	else if (isInt(literal))
	{
		std::cout << static_cast<int>(std::strtol(literal.c_str(), NULL, 10)) << std::endl;
	}
	else if (isFloat(literal))
	{
		float floatValue = static_cast<float>(std::strtod(literal.c_str(), NULL));
		if (static_cast<float>(std::numeric_limits<int>::min()) <= floatValue
		&& floatValue <= static_cast<float>(std::numeric_limits<int>::max()))
		{
			std::cout << static_cast<int>(floatValue) << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else if (isDouble(literal))
	{
		double doubleValue = std::strtod(literal.c_str(), NULL);
		if (static_cast<double>(std::numeric_limits<int>::min()) <= doubleValue
		&& doubleValue <= static_cast<double>(std::numeric_limits<int>::max()))
		{
			std::cout << static_cast<int>(doubleValue) << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	convertToFloat(const std::string& literal)
{
	std::cout << "float: ";
	if (isChar(literal))
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(literal[1]) << "f" << std::endl;
	}
	else if (isInt(literal))
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(std::strtol(literal.c_str(), NULL, 10)) << "f" << std::endl;
	}
	else if (isFloat(literal))
	{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(std::strtod(literal.c_str(), NULL)) << "f" << std::endl;
	}
	else if (isDouble(literal))
	{
		double doubleValue = std::strtod(literal.c_str(), NULL);
		if (-static_cast<double>(std::numeric_limits<float>::max()) <= doubleValue
		&& doubleValue <= static_cast<double>(std::numeric_limits<float>::max()))
		{
			std::cout << std::fixed << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(doubleValue) << "f" << std::endl;
		}
		else if (literal == std::string("nan") || literal == std::string("+inf") || literal == std::string("-inf"))
		{
			std::cout << literal << "f" << std::endl;
		}
		else
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	convertToDouble(const std::string& literal)
{
	std::cout << "double: ";
	if (isChar(literal))
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(literal[1]) << std::endl;
	}
	else if (isInt(literal))
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::strtol(literal.c_str(), NULL, 10)) << std::endl;
	}
	else if (isFloat(literal))
	{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << static_cast<double>(std::strtod(literal.c_str(), NULL)) << std::endl;
	}
	else if (isDouble(literal))
	{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << static_cast<double>(std::strtod(literal.c_str(), NULL)) << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

/* Private */
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	(void)rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

bool	isChar(const std::string& literal)
{
	if (literal.length() == 3
		&& literal[0] == '\''
		&& literal[2] == '\'')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool	isInt(const std::string& literal)
{
	char*	endPtr = NULL;
	const char*	cStr = literal.c_str();
	long	Value = std::strtol(cStr, &endPtr, 10);
	if (literal.length() != 0
		&& *endPtr == '\0'
		&& (static_cast<long>(std::numeric_limits<int>::min()) <= Value
		&& Value <= static_cast<long>(std::numeric_limits<int>::max())))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool	isFloat(const std::string& literal)
{
	if (literal == std::string("nanf")
		|| literal == std::string("+inff")
		|| literal == std::string("-inff"))
	{
		return true;
	}
	char*	endPtr = NULL;
	const char* cStr = literal.c_str();
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
	if (literal.length() >= 3
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


bool	isDouble(const std::string& literal)
{
	if (literal == std::string("nan")
	|| literal == std::string("+inf")
	|| literal == std::string("-inf"))
	{
		return true;
	}
	char* endPtr = NULL;
	const char* cStr = literal.c_str();
	double doubleValue = std::strtod(cStr, &endPtr);
	if (literal.length() >= 2
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

