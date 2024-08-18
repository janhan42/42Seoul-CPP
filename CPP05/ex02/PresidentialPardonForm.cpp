/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:39:13 by janhan            #+#    #+#             */
/*   Updated: 2024/08/18 15:08:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5)
, mTarget(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other)
, mTarget(other.getTarget())
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	throw AForm::InvalidOperatorException();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeRequiredToExecute())
		throw AForm::GradeTooLowException();
	if (getSign() == false)
		throw AForm::NotSignedException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string& PresidentialPardonForm::getTarget(void) const
{
	return mTarget;
}

void PresidentialPardonForm::setTarget(std::string& target)
{
	mTarget = target;
}
