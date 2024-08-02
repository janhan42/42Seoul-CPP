/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 09:22:36 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed()
: mValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
: mValue(fixed.mValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int num)
: mValue(num << mBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
: mValue(roundf(num * (1 << mBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		mValue = other.mValue;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (mValue > other.mValue);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (mValue < other.mValue);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (mValue >= other.mValue);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (mValue <= other.mValue);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (mValue == other.mValue);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (mValue != other.mValue);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	mValue++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	mValue--;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed temp = *this;
	mValue++;
	return (temp);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed temp = *this;
	mValue--;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (mValue);
}

void	Fixed::setRawBits(const int raw)
{
	mValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)mValue / (float)(1 << mBits);
}

int		Fixed::toInt(void) const
{
	return (mValue >> mBits);
}


std::ostream&	operator<<(std::ostream& str, const Fixed& fixed)
{
	return str << fixed.toFloat();
}
