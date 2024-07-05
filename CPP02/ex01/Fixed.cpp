/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/07/05 16:55:40 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <_stdio.h>
#include <math.h>

Fixed::Fixed(void) : mValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int num) : mValue(num << this->mBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : mValue(roundf(num * this->powInt(2, this->mBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->mValue = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->mValue);
}

void	Fixed::setRawBits(const int raw)
{
	this->mValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->mValue / (float)(this->powInt(2, this->mBits));
}

int		Fixed::toInt(void) const
{
	return (this->mValue >> this->mBits);
}


std::ostream&	operator<<(std::ostream& str, const Fixed& fixed)
{
	return str << fixed.toFloat();
}

int	Fixed::powInt(int base, int exponent) const
{
	int	res = 1;
	if (exponent == 0)
		return (1);
	else if (exponent < 0)
		return (0);
	for (int i = 0; i < exponent; i++)
		res *= base;
	return (res);
}
