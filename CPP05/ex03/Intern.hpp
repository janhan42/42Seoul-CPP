#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
		~Intern();

		class	 TypeNotFound : std::exception {};

		AForm* makeForm(std::string name, std::string target);
};

#endif
