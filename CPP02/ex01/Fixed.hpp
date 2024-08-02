/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:41 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 09:20:47 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

/*

	The previous exerciese was a good start but our class is pretty useless.
	It can only represent the value 0.0.

	Add the following public constructors and public memeber functions to your class:

		- A constructor that takes a constant integer as a parameter.
		It converts it to the corresponding fixed-point value. The fractional bits value is
		initialized to 8 like exercise 00.

		- A constructor that takes a constant floationg-point number as a parameter.
		It converts it to the corresponding fixed-point value. The faractional bits value is
		initialized to 8 like exercise 00.

		- A member function flaot toFloat( void ) const;
		that converts the fixed-point value to a floating-point value.

		- A member function in toInt( void ) const;
		that converts the fixed-point value to an integer value.

	And add the following function to the Fixed class files:
		- An overload of the insertion( << ) operator that inserts a floating-point representation
		of the fixed-point number into the output stream object passed as parameter.

 */

class Fixed
{
	public:
		Fixed();								/* Default constructor */
		Fixed(const Fixed& fixed);				/* Copy constructor */
		Fixed(const int num);					/* Int constructor */
		Fixed(const float num);					/* float constructor */
		Fixed&	operator=(const Fixed& other);	/* Copy assignment operator */
		~Fixed();								/* Destructor */

		int		getRawBits(void) const;			/* Subject function */
		void	setRawBits(const int raw);		/* Subject function */
		float	toFloat(void) const;			/* Subject function */
		int		toInt(void) const;				/* Subject function */
	private:
		int	mValue;								/* integer to store the fixed-point number value */
		static const int mBits = 8;				/* ststic constant integer to store the number of fractional bits*/
};

std::ostream&	operator<<(std::ostream &str, const Fixed& fixed); /* overload of the istretion (<<) operator */
