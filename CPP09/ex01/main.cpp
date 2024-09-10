/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:14:09 by janhan            #+#    #+#             */
/*   Updated: 2024/09/09 14:35:29 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "RPN.hpp"

// 입력 ./RPN "8 9 * 9 - 9 - 4 - 1 +"
	/*
		들어왔을때 부호 랑 숫자를 저장해야함.
	 */
static void insertString(char* av, RPN& rpn)
{
	for (std::size_t i = 0; av[i]; ++i)
	{
		if (i % 2 == 0 && av[i] != ' ')
			rpn.insert(av[i]);
		else if (i % 2 == 1 && av[i] == ' ')
			continue;
		else
			throw RPN::ExpressionException();
	}
}

int main(int ac, char**av)
{
	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	RPN rpn;
	try
	{
		insertString(av[1], rpn);
		std::cout << rpn.result() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error" << std::endl;
	}
	return (0);
}
