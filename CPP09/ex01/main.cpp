/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:14:09 by janhan            #+#    #+#             */
/*   Updated: 2024/10/01 00:21:59 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "RPN.hpp"


// static void insertString(char* av, RPN& rpn)
// {
// 	for (std::size_t i = 0; av[i]; ++i)
// 	{
// 		if (i % 2 == 0 && av[i] != ' ')
// 			rpn.insert(av[i]);
// 		else if (i % 2 == 1 && av[i] == ' ')
// 			continue;
// 		else
// 			throw RPN::ExpressionException();
// 	}
// }

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
		rpn.insertString(av[1]);
		std::cout << rpn.result() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error" << std::endl;
	}
	return (0);
}
