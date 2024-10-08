#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

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
		int					getGrade(void) const;

		/* increase & decrease */
		void				increaseGrade(void);
		void				decreaseGrade(void);

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
