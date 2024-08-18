/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequsetForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:58:45 by janhan            #+#    #+#             */
/*   Updated: 2024/08/18 15:02:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUSETFORM_HPP
# define ROBOTOMYREQUSETFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <string>
#include <iostream>

class RobotomyRequsetForm : public AForm
{
	public:
		/* OCCF */
		RobotomyRequsetForm(std::string target);
		RobotomyRequsetForm(const RobotomyRequsetForm& other);
		RobotomyRequsetForm& operator=(const RobotomyRequsetForm& other);
		virtual ~RobotomyRequsetForm();

		virtual void execute(const Bureaucrat& bureaucrat) const;
	private:
		std::string mTarget;
		const std::string& getTarget(void) const;
		void				setTarget(void) const;
};

#endif
