/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:40:15 by janhan            #+#    #+#             */
/*   Updated: 2024/08/22 18:58:27 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <exception>

void	check(void)
{
	system("leaks Bureaucrat");
}

int main()
{
	/* TEST for Intern */
	{
		Intern	unit;
		AForm*	paper;
		try
		{
			paper = unit.makeForm("Presidential pardon", "you");
		}
		catch (const Intern::TypeNotFound& e)
		{
			std::cout << "Somthing Wrong." << std::endl;
		}
		std::cout << *paper << std::endl << std::endl;
		Bureaucrat	janhan("Janhan", 3);
		janhan.signForm(*paper);
		janhan.executeForm(*paper);

		std::cout << std::endl << *paper << std::endl << std::endl;
		delete paper;
	}
	/* TEST Exception */
	{
		Intern unit;
		AForm* WrongForm;
		try
		{
			WrongForm = unit.makeForm("No Form", "NONE");
		}
		catch (const Intern::TypeNotFound& e)
		{
			std::cerr << "SomeThig Worng" << std::endl;
		}
		delete WrongForm;
	}
	atexit(check);
	return (0);
}
