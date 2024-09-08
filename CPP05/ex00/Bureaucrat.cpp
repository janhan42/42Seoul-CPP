/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:37:39 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 10:23:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
: mName(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: mName(other.mName)
, mGrade(other.mGrade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	(void)other;
	throw InvalidOperator();
}

Bureaucrat::~Bureaucrat()
{
}

const std::string&	Bureaucrat::getName() const
{
	return mName;
}

int	Bureaucrat::getGrade() const
{
	return mGrade;
}

void	Bureaucrat::increaseGrade()
{
	setGrade(mGrade - 1);
}

void	Bureaucrat::decreaseGrade()
{
	setGrade(mGrade + 1);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw	GradeTooHighException();
	if (grade > 150)
		throw	GradeTooLowException();
	mGrade = grade;
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}

/* Excpetion */
const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat Grade Too High Exception";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat Grade Too Low Exception";
}

const char* Bureaucrat::InvalidOperator::what(void) const throw()
{
	return "Bureaucrat InvalidOperator Exception";
}

const char* Bureaucrat::InvalidConstructor::what(void) const throw()
{
	return "Bureaucrat Invalid Contructor Exception";
}
