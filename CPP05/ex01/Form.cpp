/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:02:27 by janhan            #+#    #+#             */
/*   Updated: 2024/08/17 09:42:48 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int greadRequiredToSign, int gradeRequiredToExecute)
: mName(name)
, mSigned(false)
, mGradeRequiredToSign(greadRequiredToSign)
, mGradeRequiredToExecute(gradeRequiredToExecute)
{
	validGrade(mGradeRequiredToSign);
	validGrade(mGradeRequiredToExecute);
}

Form::Form(const Form& other)
: mName(other.mName)
, mSigned(false)
, mGradeRequiredToSign(other.mGradeRequiredToSign)
, mGradeRequiredToExecute(other.mGradeRequiredToExecute)
{
}

Form&	Form::operator=(const Form &other)
{
	(void)other;
	throw Form::InvalidOperatorException();
}

Form::~Form()
{
}

const std::string&	Form::getName() const
{
	return mName;
}

const bool&	Form::getSign() const
{
	return mSigned;
}

int	Form::getGradeRequiredToSing() const
{
	return mGradeRequiredToSign;
}

int	Form::getGradeRequiredToExecute() const
{
	return mGradeRequiredToExecute;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (mSigned)
		throw Form::DoubleSignException();
	if (bureaucrat.getGrade() > mGradeRequiredToSign)
		throw Form::GradeTooLowException();
	setIsSigned(true);
}

/* PRIVATE */
void	Form::setIsSigned(bool flag)
{
	mSigned = flag;
}

void	Form::validGrade(int gread)
{
	if (gread < 1)
		throw Form::GradeTooHighException();
	if (gread > 150)
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	std::string result;

	if (rhs.getSign())
		result = "Signed";
	else
		result = "Not Signed";
	os	<< "Form Name : " << rhs.getName()
		<< "\nSign: " << rhs.getSign()
		<< "\nRequired grade to sign: " << rhs.getGradeRequiredToSing()
		<< "\nRequired gread to Execute: " << rhs.getGradeRequiredToExecute();

	return os;
}
