/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isDateFormat.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:54:16 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 08:55:22 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ISDATEFORMAT_HPP
# define ISDATEFORMAT_HPP

#include <string>
#include <cstdlib>

#include "split.hpp"

bool	isLeepYear(long year);
bool	isDateFormat(const std::string& str);

#endif
