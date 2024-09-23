/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:03:44 by jeekpark          #+#    #+#             */
/*   Updated: 2024/09/23 17:43:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array();
		Array(const unsigned int n);
		Array(const Array& rhs);
		Array&	operator=(const Array& rhs);
		~Array();
		T&	operator[](const unsigned int i) const;
		unsigned int	size(void) const;

	private:
		unsigned int	mLength;
		T*				mArray;
};

#include "Array.tpp"

#endif
