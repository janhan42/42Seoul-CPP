/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:36:04 by janhan            #+#    #+#             */
/*   Updated: 2024/08/23 02:20:39 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main(void)
{
	/* Sign Form */
	{
		Bureaucrat unit("Janhan", 7);
		Form CPP04("CPP04", 10, 10);

		std::cout << "Before Signed " << std::endl << CPP04 << std::endl << std::endl;
		unit.signForm(CPP04);
		std::cout << "After Signed " << std::endl << CPP04 << std::endl;

		std::cout << std::endl;
	}

	/* Form::DoubleSignException */
	{
		Bureaucrat unit("Janhan", 7);
		Form CPP06("CPP06", 10, 10);

		std::cout << "DoubleSignException TEST\nBefore Signed\n" << CPP06 << std::endl << std::endl;
		unit.signForm(CPP06);
		unit.signForm(CPP06);
		std::cout << std::endl;
	}

	/* Form::GradeTooLowException */
	{
		Bureaucrat unit("Janhan", 7);
		Form CPP07("CPP07", 1, 1);

		std::cout << "GradeTooLowException TEST" << std::endl;
		unit.signForm(CPP07);
		std::cout << std::endl;
	}
	return 0;
}
