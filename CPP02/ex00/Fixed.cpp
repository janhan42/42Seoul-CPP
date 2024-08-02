/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 09:20:30 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructor */
Fixed::Fixed()
: mValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* Copy Constructor */
Fixed::Fixed(const Fixed& fixed)
: mValue(fixed.mValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

/* Copy Assignment Operator */
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		mValue = other.mValue;
	return (*this);
}

/* Destructor */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
