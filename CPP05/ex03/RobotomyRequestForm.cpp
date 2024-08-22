/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/23 02:37:54 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45)
, mTarget(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other)
, mTarget(other.getTarget())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	throw AForm::InvalidOperatorException();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeRequiredToExecute())
		throw AForm::GradeTooLowException();
	if (getSign() == false)
		throw AForm::NotSignedException();
	std::cout << "Drill!!!!!!!!!!!!!!!!!!!!" << std::endl;
	srand(time(0));
	if (std::rand() % 2)
		std::cout << getTarget() << " is robot now." << std::endl;
	else
		std::cout << getTarget() << " is failed to be robot." << std::endl;
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return mTarget;
}

void	RobotomyRequestForm::setTarget(std::string target)
{
	mTarget = target;
}
