/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:49:35 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 05:46:22 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// 그냥 std::cin 과 std::getline(std::cin, str) 의 차이 점
// std::string이 왜 길이 없이 받을수 있는지
// 그럼에도 std::string::c_str이 있는 이유
int main( int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		for (int j = 0; str[j]; j++)
			str[j] = std::toupper(str[j]);
		std::cout << str;

	}
	std::cout << std::endl;
	return (0);
}
