/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:36:04 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 09:56:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

void check(void)
{
	system("leaks Bureaucrat");
}

int main(void)
{
	/*
		Test for ShrubberyCreationForm
	 */
	{
		std::cout << "------ ShrubberyCreationForm ------" << std::endl;
		Bureaucrat	badUnit("Bad Sign", 146);
		Bureaucrat	badUnit2("Bad Execute", 136);
		Bureaucrat	unit("Janhan", 7);

		AForm*		paper = new ShrubberyCreationForm("home");

		badUnit.signForm(*paper);
		std::cout << std::endl;
		badUnit2.signForm(*paper);
		std::cout << std::endl;
		unit.signForm(*paper);
		std::cout << std::endl;
		badUnit.executeForm(*paper);
		std::cout << std::endl;
		unit.executeForm(*paper);

		std::cout << *paper << std::endl << std::endl;
		std::cout << "---------------------------------" << std::endl;
		delete paper;
	}

	/*
		Test for RobotomyRequestForm
	 */
	{
		std::cout << "------ RobotomyRequestForm ------" << std::endl;
		Bureaucrat	badUnit("Bad Sign", 73);
		Bureaucrat	badUnit2("Bad Execute", 46);
		Bureaucrat	unit("Janhan", 7);

		AForm*		paper = new RobotomyRequestForm("sangshin");
		std::cout << *paper << std::endl;

		badUnit.signForm(*paper);
		std::cout << std::endl;
		badUnit2.signForm(*paper);
		std::cout << std::endl;
		unit.signForm(*paper);
		std::cout << std::endl;
		badUnit.executeForm(*paper);
		std::cout << std::endl;
		unit.executeForm(*paper);
		std::cout << *paper << std::endl << std::endl;
		std::cout << "---------------------------------" << std::endl;
		delete paper;
	}

	/* Test for PresidentialPardonForm */
	{
		std::cout << "------ PresidentialPardonForm ------" << std::endl;
		Bureaucrat	badUnit("Bad Sign", 26);
		Bureaucrat	badUnit2("Bad Execute", 6);
		Bureaucrat	unit("Janhan", 5);

		AForm*		paper = new PresidentialPardonForm("sangshin");
		std::cout << *paper << std::endl;

		badUnit.signForm(*paper);
		std::cout << std::endl;
		badUnit2.signForm(*paper);
		std::cout << std::endl;
		unit.signForm(*paper);
		std::cout << std::endl;
		badUnit.executeForm(*paper);
		std::cout << std::endl;
		unit.executeForm(*paper);
		std::cout << *paper << std::endl << std::endl;
		std::cout << "---------------------------------" << std::endl;
		delete paper;
	}
	//atexit(check);
	return 0;
}
