#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#include <exception>
#include <stack>
#include <string>

class RPN
{
	public:
		/* OCCf */
		RPN();
		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);
		~RPN();
		void		insertString(char* av);
		void		insert(char c);
		double		result(void) const;

		class ExpressionException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
	private:
		/* std::stack<double> use */
		std::stack<double>	mStack;

		void		push(double n);
		void		pop(void);
		double		top(void) const;
		size_t		size(void) const;
};

#endif
