/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 07:01:56 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int num) : _value(num << this->_bits)
{}

Fixed::Fixed(const float num) : _value(roundf(num * this->_pow_int(2, this->_bits)))
{}

Fixed::~Fixed(void)
{}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other.getRawBits();
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
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed temp = *this;
	this->_value++;
	return (temp);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed temp = *this;
	this->_value--;
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
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(this->_pow_int(2, this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
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
