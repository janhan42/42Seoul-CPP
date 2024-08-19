/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:58:45 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 15:47:05 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <string>
#include <iostream>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		/* OCCF */
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		virtual void execute(const Bureaucrat& bureaucrat) const;
	private:
		std::string			mTarget;
		const std::string&	getTarget(void) const;
		void				setTarget(std::string target);
};

#endif
