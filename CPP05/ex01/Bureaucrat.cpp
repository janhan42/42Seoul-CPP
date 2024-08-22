/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:17:28 by janhan            #+#    #+#             */
/*   Updated: 2024/08/23 02:17:29 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
: mName(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: mName(other.mName)
{
	setGrade(mGrade);
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

const int&	Bureaucrat::getGrade() const
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

/* ex01 Function */
void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch(const Form::DoubleSignException& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
				<< " because this form is already signed." << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
				<< " because " << getName() << "(grade: " << getGrade() << ")"
				<< " is below the required grade(" << form.getGradeRequiredToSing() << ") to sign." << std::endl;
	}
}


/* PRIVATE */
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
