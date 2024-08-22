/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:18:09 by janhan            #+#    #+#             */
/*   Updated: 2024/08/23 02:18:10 by janhan           ###   ########.fr       */
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
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
		class InvalidConstructor : public std::exception {};
		class InvalidOperator : public std::exception {};


	private:
		const std::string	mName;
		int					mGrade;
		void				setGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& rhs);

#endif
