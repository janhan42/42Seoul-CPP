/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:24:12 by janhan            #+#    #+#             */
/*   Updated: 2024/08/31 17:25:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template<typename Tarry, typename Tfunction> void iter(Tarry arr, size_t length, Tfunction func)
{
	for (size_t i = 0; i < length; ++i)
		func(arr[i]);
}

#endif
