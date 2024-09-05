/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:53:37 by janhan            #+#    #+#             */
/*   Updated: 2024/09/02 17:08:22 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int i);

#include "easyfind.tpp"

#endif
