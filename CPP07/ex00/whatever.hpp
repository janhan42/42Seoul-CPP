/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:50:15 by janhan            #+#    #+#             */
/*   Updated: 2024/08/29 00:52:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T> void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> const T& min(const T& a, const T& b) {return a < b ? a : b; }
template<typename T> const T& max(const T& a, const T& b) {return a > b ? a : b; }


#endif
