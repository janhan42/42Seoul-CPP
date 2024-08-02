/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:41 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 09:20:24 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

/*

	Create a class in Orthodox Canonical Form that represents a fixed-porint numer:

	- Private member:
		- An integer to store the fixed-point number value.
		- A static constant integer to store the number of fractional bits.
		Its value will always be the integer literal 8.

	- Public member:
		- A default constructor that inialize the fixed-point number value to 0.
		- A copy constructor.
		- A copy assignment operetor overload.
		- A detructor.
		- A member function int getRawBits( void ) const;
		that returns the raw value of the fixed-point value.
		- A member function void setRawBits( int const raw );
		that sets the raw value of the fixed-point number.
 */

class Fixed
{
	public:
		Fixed();								/* Default constructor */
		Fixed(const Fixed& fixed);				/* Copy Constructor */
		Fixed &operator=(const Fixed& other);	/* Copy Assignment Operator */
		~Fixed();								/* Destructor */

		int		getRawBits(void) const;			/* Subject function */
		void	setRawBits(const int raw);		/* Subject function */
	private:
		int	mValue;								/* integer to store the fixed-point number value */
		static const int mBit = 8;				/* ststic constant integer to store the number of fractional bits*/
};

