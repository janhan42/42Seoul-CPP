/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:58:49 by janhan            #+#    #+#             */
/*   Updated: 2024/08/23 03:22:56 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHURBBERYCREATIONFORM_HPP
# define SHURBBERYCREATIONFORM_HPP

#include <fstream>
#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		/* OCCF */
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		/* Exception */
		class	FailedToFileOpen : public std::exception {};
		class	FailedToFileWrite : public std::exception {};

		virtual void execute(const Bureaucrat& bureaucrat) const;
	private:
		std::string			mTarget;
		const std::string&	getTarget(void) const;
		void				setTarget(std::string target);
};

#endif
