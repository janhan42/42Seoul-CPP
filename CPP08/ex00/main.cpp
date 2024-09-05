/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:09:14 by janhan            #+#    #+#             */
/*   Updated: 2024/09/02 17:29:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vector(10);
	std::vector<int>::iterator it;
	for (size_t i = 0; i < 10; ++i)
	{
		vector.push_back(i);
	}

	try
	{
		it = easyfind(vector, 6);
		std::cout << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Can't find." << std::endl;
	}

	try
	{
		it = easyfind(vector, 11);
		std::cout << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Can't find." << std::endl;
	}
}
