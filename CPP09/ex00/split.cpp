/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 06:16:43 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 06:19:17 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.hpp"
/**
 * @brief
 * 들어온 str(std::string)을 구분자(char c)로 나누어 std::list에 담아서 리턴
 * @param str
 * @param c
 * @return std::list<std::string>
 */
std::list<std::string> split(const std::string& str, char c)
{
	std::list<std::string> tokens;
	std::string token;
	std::istringstream stream(str);

	while (std::getline(stream, token, c))
	{
		tokens.push_back(token);
	}
	return tokens;
}
