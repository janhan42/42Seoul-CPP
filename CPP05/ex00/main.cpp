/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:36:04 by janhan            #+#    #+#             */
/*   Updated: 2024/08/17 08:44:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main(void)
{
	/* Test Bureaucrat::GradeTooHighException */
	{
		Bureaucrat unit("janhan", 10);
		try
		{
			for(;;)
			{
				unit.increaseGrade();
				std::cout << unit << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	/* Test Bureaucrat::GradeTooLowException */
	{
		Bureaucrat unit("janhan", 140);
		try
		{
			for(;;)
			{
				unit.decreaseGrade();
				std::cout << unit << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}