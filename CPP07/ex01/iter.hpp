/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:24:12 by janhan            #+#    #+#             */
/*   Updated: 2024/09/23 17:43:31 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

/**
 * @brief
 * Tarry형의 arr에 T형 func에 arr[i]를 매개변수에 넣어서 호출하는 함수
 * @tparam Tarry
 * @tparam Tfunction
 * @param arr
 * @param length
 * @param func
 */
template<typename Tarry, typename Tfunction>
void iter(Tarry arr, size_t length, Tfunction func)
{
	for (size_t i = 0; i < length; ++i)
		func(arr[i]);
}

#endif
