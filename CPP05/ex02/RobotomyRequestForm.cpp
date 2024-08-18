/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:05:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/18 15:07:37 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequsetForm.hpp"

RobotomyRequsetForm::RobotomyRequsetForm(std::string target)
: AForm("RobotomyRequsetForm", 72, 45)
, mTarget(target)
{
}

RobotomyRequsetForm::RobotomyRequsetForm(const RobotomyRequsetForm& other)
: AForm(other)
, mTarget(other.getTarget())
{
}

RobotomyRequsetForm::~RobotomyRequsetForm()
{
}
