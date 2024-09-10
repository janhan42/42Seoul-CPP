/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:37:17 by janhan            #+#    #+#             */
/*   Updated: 2024/09/09 21:43:36 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstddef>

RPN::RPN()
{}

RPN::RPN(const RPN& rhs)
: mStack(rhs.mStack)
{}

RPN& RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		mStack = rhs.mStack;
	}
	return (*this);
}

RPN::~RPN()
{}

void	RPN::clear(void)
{
	mStack = std::stack<double>();
}

void	RPN::insert(char c)
{
	if (std::isdigit(static_cast<int>(c)))
	{
		push(c - '0');
		return ;
	}
	if (size() < 2)
		throw RPN::ExpressionException();
	double a, b;
	switch (c)
	{
		case '+':
			a = top(); pop();
			b = top(); pop();
			push(b + a);
			break;
		case '-':
			a = top(); pop();
			b = top(); pop();
			push(b - a);
			break;
		case '*':
			a = top(); pop();
			b = top(); pop();
			push(b * a);
			break;
		case '/':
			a = top(); pop();
			b = top(); pop();
			push(b / a);
			break;
		default:
			throw RPN::ExpressionException();
	}
}

double	RPN::result(void) const
{
	if (size() == 1)
		return top();
	else
		throw RPN::ExpressionException();
}

const char*	RPN::ExpressionException::what(void) const throw()
{
	return "Incomplete Expression";
}

/* Private */
void	RPN::push(double n)
{
	mStack.push(n);
}

void	RPN::pop(void)
{
	mStack.pop();
}

double	RPN::top(void) const
{
	return mStack.top();
}

size_t	RPN::size(void) const
{
	return mStack.size();
}
