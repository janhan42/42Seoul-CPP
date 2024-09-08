/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:09:33 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 10:27:41 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Form
{
	public:
		/* OCCF */
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		/* Exception */
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class	InvalidOperatorException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class	DoubleSignException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		/* Functions */
		const std::string&	getName(void) const;
		const bool&			getSign(void) const;
		int					getGradeRequiredToSing(void) const;
		int					getGradeRequiredToExecute(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);

	private:
		const std::string	mName;
		bool				mSigned;
		const int			mGradeRequiredToSign;
		const int			mGradeRequiredToExecute;

		void				setIsSigned(bool flag);
		void				validGrade(int grade);
};

std::ostream&	operator<<(std::ostream& os, const Form& rhs);


#endif
