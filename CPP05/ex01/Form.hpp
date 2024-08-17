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
		Form(std::string name, int greadRequiredToSign, int gradeRequiredToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		/* Exception */
		class	GradeTooHighException : public std::exception {};
		class	GradeTooLowException : public std::exception {};
		class	InvalidOperatorException : public std::exception {};
		class	DoubleSignException : public std::exception {};

		/* Functions */
		const std::string&	getName(void) const;
		const bool&			getSign(void) const;
		int					getGradeRequiredToSing(void) const;
		int					getGradeRequiredToExecute(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);

	private:
		const std::string	mName;
		bool				mSigned;					/* Sign 상태 */
		const int			mGradeRequiredToSign;		/* 서명하는 데 필요한 상수 등급 */
		const int			mGradeRequiredToExecute;	/* 실행하는 데 필요한 상수 등급 */

		void				setIsSigned(bool flag);
		static void			validGrade(int grade);
};

std::ostream&	operator<<(std::ostream& os, const Form& rhs);


#endif
