/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:50:15 by janhan            #+#    #+#             */
/*   Updated: 2024/09/23 17:43:32 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/**
 * @brief
 * T 형의 인자 a와 b의 값을 swap하는 템플릿 함수
 * @tparam T
 * @param a
 * @param b
 */
template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

/**
 * @brief
 * T 형의 인자 a와 b중에 작은 값을 리턴하는 함수
 * @tparam T
 * @param a
 * @param b
 * @return const T&
 */
template<typename T>
const T& min(const T& a, const T& b)
{
	return a < b ? a : b;
}

/**
 * @brief
 * T 형의 인자 a와 b중에 큰 값을 리턴하는 함수
 * @tparam T
 * @param a
 * @param b
 * @return const T&
 */
template<typename T>
const T& max(const T& a, const T& b)
{
	return a > b ? a : b;
}

#endif
