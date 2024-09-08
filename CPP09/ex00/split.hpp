/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 06:15:32 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 06:16:28 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPLIT_HPP
# define SPLIT_HPP

#include <list>
#include <string>
#include <sstream>

std::list<std::string> split(const std::string& str, char c);

#endif
