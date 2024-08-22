/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:33:58 by janhan            #+#    #+#             */
/*   Updated: 2024/08/18 14:59:02 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>
#include <iostream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		/* OCCF */
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

		virtual void	execute(const Bureaucrat& bureaucrat) const;
	private:
		std::string		mTarget;
		const std::string&	getTarget(void) const;
		void				setTarget(std::string& target);
};

#endif
