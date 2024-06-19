/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:41 by janhan            #+#    #+#             */
/*   Updated: 2024/06/20 06:22:50 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);						// Default constructor
		Fixed(const Fixed& fixed);			// Copy constructor
		Fixed &operator=(const Fixed& other);	// Copy assignment operator
		~Fixed(void);						// Destructor
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int	_value;
		static const int _bit = 8;
};

#endif
