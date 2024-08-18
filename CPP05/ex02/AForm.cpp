/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:02:27 by janhan            #+#    #+#             */
/*   Updated: 2024/08/17 09:42:48 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int greadRequiredToSign, int gradeRequiredToExecute)
: mName(name)
, mSigned(false)
, mGradeRequiredToSign(greadRequiredToSign)
, mGradeRequiredToExecute(gradeRequiredToExecute)
{
	validGrade(mGradeRequiredToSign);
	validGrade(mGradeRequiredToExecute);
}

AForm::AForm(const AForm& other)
: mName(other.mName)
, mSigned(false)
, mGradeRequiredToSign(other.mGradeRequiredToSign)
, mGradeRequiredToExecute(other.mGradeRequiredToExecute)
{
}

AForm&	AForm::operator=(const AForm &other)
{
	(void)other;
	throw AForm::InvalidOperatorException();
}

AForm::~AForm()
{
}

const std::string&	AForm::getName() const
{
	return mName;
}

const bool&	AForm::getSign() const
{
	return mSigned;
}

int	AForm::getGradeRequiredToSing() const
{
	return mGradeRequiredToSign;
}

int	AForm::getGradeRequiredToExecute() const
{
	return mGradeRequiredToExecute;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (mSigned)
		throw AForm::DoubleSignException();
	if (bureaucrat.getGrade() > mGradeRequiredToSign)
		throw AForm::GradeTooLowException();
	setIsSigned(true);
}

/* PRIVATE */
void	AForm::setIsSigned(bool flag)
{
	mSigned = flag;
}

void	AForm::validGrade(int gread)
{
	if (gread < 1)
		throw AForm::GradeTooHighException();
	if (gread > 150)
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	std::string result;

	if (rhs.getSign())
		result = "Signed";
	else
		result = "Not Signed";
	os	<< "AForm Name : " << rhs.getName()
		<< "\nSign: " << rhs.getSign()
		<< "\nRequired grade to sign: " << rhs.getGradeRequiredToSing()
		<< "\nRequired gread to Execute: " << rhs.getGradeRequiredToExecute();

	return os;
}
