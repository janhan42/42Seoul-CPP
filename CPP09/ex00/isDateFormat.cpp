/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isDateFormat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:55:34 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 09:01:18 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isDateFormat.hpp"

bool	isLeepYear(long year)
{
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool	isDateFormat(const std::string &str)
{
	if (str.length() != 10)
		return false;
	for (std::size_t i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
		{
			if (str[i] != '-')
				return false;
		}
		else
		{
			if (std::isdigit(str[i] == false))
				return false;
		}
	}
	std::list<std::string> splited = split(str, '-');
	long year = std::strtol(splited.front().c_str(), NULL, 10);
	std::list<std::string>::iterator it = splited.begin();
	it++;
	long month = std::strtol((*it).c_str(), NULL, 10);
	it++;
	long day = std::strtol((*it).c_str(), NULL, 10);
	if ((1 <= month && month <= 12) == false)
		return false;
	if ((1 <= day) == false)
		return false;
	const int daysInMonth[12] = {31, isLeepYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return day <= daysInMonth[month - 1];
}
