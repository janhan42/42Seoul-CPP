/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 08:19:39 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: mValue(0)
{}

Fixed::Fixed(const Fixed& fixed)
: mValue(fixed.mValue)
{}

Fixed::Fixed(const int num)
: mValue(num << mBits)
{}

Fixed::Fixed(const float num)
: mValue(roundf(num * mPowInt(2, mBits)))
{}

Fixed::~Fixed()
{}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		mValue = other.getRawBits();
	return (*this);
}


bool	Fixed::operator>(const Fixed& other) const
{
	return (getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (getRawBits() != other.getRawBits());
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
	return (mValue);
}

void	Fixed::setRawBits(const int raw)
{
	mValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)mValue / (float)(mPowInt(2, mBits));
}

int		Fixed::toInt(void) const
{
	return (mValue >> mBits);
}


std::ostream&	operator<<(std::ostream& str, const Fixed& fixed)
{
	return str << fixed.toFloat();
}

int	Fixed::mPowInt(int base, int exponent) const
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
