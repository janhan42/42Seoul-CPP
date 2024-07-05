/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:41 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 07:01:27 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Fixed
{
	public:
		Fixed(void);							// Default constructor
		Fixed(const Fixed& fixed);				// Copy constructor
		Fixed &operator=(const Fixed& other);	// Copy assignment operator
		~Fixed(void);							// Destructor

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
	private:
		int	mValue;
		static const int mBit = 8;
};
