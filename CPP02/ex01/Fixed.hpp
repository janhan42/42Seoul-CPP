/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:41 by janhan            #+#    #+#             */
/*   Updated: 2024/06/21 15:45:05 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);							// Default constructor
		Fixed(const Fixed& fixed);				// Copy constructor
		Fixed(const int num);					// Int constructor [ ]
		Fixed(const float num);					// float constructor [ ]
		~Fixed(void);							// Destructor
		Fixed&	operator=(const Fixed& other);	// Copy assignment operator
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int	_value;
		static const int _bits = 8;
		int	_pow_int(int base, int exponent) const;
};

std::ostream&	operator<<(std::ostream &str, const Fixed& fixed); // overload of the istretion (<<) operator

#endif
