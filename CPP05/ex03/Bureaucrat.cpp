/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:18:13 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 10:26:17 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

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
void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch(const AForm::DoubleSignException& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
				<< " because this form is already signed." << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
				<< " because " << getName() << "(grade: " << getGrade() << ")"
				<< " is below the required grade(" << form.getGradeRequiredToSing() << ") to sign." << std::endl;
	}
}

/* ex02 Function */
void	Bureaucrat::executeForm(AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " execute " << form.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << getName() << " could't execute " << form.getName()
				<< " because " << getName() << "(grade: " << getGrade() << ") (Excute grade: "
				<< form.getGradeRequiredToExecute() << ") to execute." << std::endl;
	}
	catch(const AForm::NotSignedException& e)
	{
		std::cout << "Failed to execute. This form is not signed." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "A technical problem has occurred." << std::endl;
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
