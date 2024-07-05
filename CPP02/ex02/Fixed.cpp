/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/07/05 16:57:33 by janhan           ###   ########.fr       */
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

Fixed::Fixed(const float num) : mValue(roundf(num * this->_pow_int(2, this->mBits)))
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


bool	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	this->mValue++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->mValue--;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed temp = *this;
	this->mValue++;
	return (temp);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed temp = *this;
	this->mValue--;
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
	return (this->mValue);
}

void	Fixed::setRawBits(const int raw)
{
	this->mValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->mValue / (float)(this->_pow_int(2, this->mBits));
}

int		Fixed::toInt(void) const
{
	return (this->mValue >> this->mBits);
}


std::ostream&	operator<<(std::ostream& str, const Fixed& fixed)
{
	return str << fixed.toFloat();
}

int	Fixed::_pow_int(int base, int exponent) const
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
