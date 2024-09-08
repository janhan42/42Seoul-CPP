/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:17:40 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 10:25:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	public:
		/* OCCF */
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		/* Getter */
		const std::string&	getName(void) const;
		const int&			getGrade(void) const;

		/* increase & decrease */
		void				increaseGrade(void);
		void				decreaseGrade(void);

		/* ex01 Function */
		void				signForm(AForm& form) const;

		/* ex02 Function */
		void	executeForm(AForm& form) const;

		/* Exception */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class InvalidConstructor : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class InvalidOperator : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};


	private:
		const std::string	mName;
		int					mGrade;
		void				setGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& rhs);

#endif
