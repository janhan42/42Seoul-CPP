/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:18:18 by janhan            #+#    #+#             */
/*   Updated: 2024/08/23 03:54:20 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <string>
#include <sys/_types/_size_t.h>

Intern::Intern()
{}

Intern::Intern(const Intern& rhs)
{
	(void)rhs;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{}

static AForm*	newShurubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm*	newRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	newPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	const size_t	formNum = 3;
	std::string	formTypes[formNum] =
	{
		"shurubbery creation",
		"robotomy request",
		"Presidential pardon"
	};
	AForm* (*f[formNum])(std::string) =
	{
		newShurubberyCreationForm,
		newRobotomyRequestForm,
		newPresidentialPardonForm
	};
	for (size_t i = 0; i < formNum; ++i)
	{
		if (formTypes[i] == name)
		{
			std::cout << "Intern Creates " << name << "Form" << std::endl;
			return f[i](target);
		}
	}
	throw Intern::TypeNotFound();
	return (AForm*)0;
}

