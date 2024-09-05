/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:21 by janhan            #+#    #+#             */
/*   Updated: 2024/09/02 17:30:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iterator>
#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw std::exception();
	return it;
}

#endif
