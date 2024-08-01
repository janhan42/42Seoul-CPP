/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:41 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 08:48:20 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

/*

	Add pulic member functuons to your class to overload
	the following operators:
		- The 6 comparison operator >, <, >=, <=, == and !=.
		- The 4 arithmetic operator +, -, *, and /.
		- THe 4 increment/decrement (pre-increment and post-increment, pre-decrement and
		post-decrement) operators, that will increase or decrease the fixed-point value from
		the smallest representable ε such as 1 + ε > 1.

	Add these four public overloaded member functions to your class:
		- A static member function 'min' that takes as parameters two references on fixed-point
		number, and returns a reference to the smallest one.

		- A static member function 'min' that takes as parameters two refernces to 'constant'
		fixed-point number, and returns a reference a reference to the smallest one.

		- A static member function 'max' that takes as parameters two references on fixed-point
		numbers, and returns a reference to the greatest one.

		- A static member function 'max' that takes as parameters two references to 'constant'
		fixed-point numbers, and returns a reference to hte greatest one.
 */

class Fixed
{
	public:
		Fixed();										/* Default constructor */
		Fixed(const Fixed& fixed);						/* Copy constructor */
		Fixed(const int num);							/* Int constructor [ ] */
		Fixed(const float num);							/* float constructor [ ] */
		Fixed&	operator=(const Fixed& other);			/* Copy assignment operator */
		~Fixed();										/* Destructor */

		/* comparison operator overload */
		bool	operator>(const Fixed& other) const;	/* > overload */
		bool	operator<(const Fixed& other) const;	/* < overload */
		bool	operator>=(const Fixed& other) const;	/* >= overload */
		bool	operator<=(const Fixed& other) const;	/* <= overload */
		bool	operator==(const Fixed& other) const;	/* == overload */
		bool	operator!=(const Fixed& other) const;	/* != overload */

		/* arithmetic operator overload */
		Fixed	operator+(const Fixed& other) const;	/* + overlaod */
		Fixed	operator-(const Fixed& other) const;	/* - overload */
		Fixed	operator*(const Fixed& other) const;	/* * overload */
		Fixed	operator/(const Fixed& other) const;	/* / overload */

		/* increment/decrement operator overload */
		Fixed&	operator++(void);						/* pre++ overload */
		Fixed&	operator--(void);						/* pre-- overload */
		const Fixed	operator++(int);					/* post++ overload */
		const Fixed	operator--(int);					/* post-- overload */

		/* Subeject Function min/max */
		static Fixed& min(Fixed& a, Fixed& b);			/* Subject function */
		static Fixed& max(Fixed& a, Fixed& b);			/* Subject function */

		/* Subject Function constant min/max */
		static const Fixed& min(const Fixed& a, const Fixed& b);	/* Subject function */
		static const Fixed& max(const Fixed& a, const Fixed& b);	/* Subject function */

		int		getRawBits(void) const;					/* Subject function */
		void	setRawBits(const int raw);				/* Subject function */
		float	toFloat(void) const;					/* Subject function */
		int		toInt(void) const;						/* Subject function */
	private:
		int	mValue;										/* integer to store the fixed-point number value */
		static const int mBits = 8;						/* ststic constant integer to store the number of fractional bits*/
};

std::ostream&	operator<<(std::ostream &str, const Fixed& fixed); /* overload of the istretion (<<) operator */
