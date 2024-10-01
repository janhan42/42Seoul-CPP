/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:37:17 by janhan            #+#    #+#             */
/*   Updated: 2024/10/01 00:31:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstddef>

/* Default Constructor */
RPN::RPN()
{}

/* Copy Constructor */
RPN::RPN(const RPN& rhs)
: mStack(rhs.mStack)
{}

/* Copy Assignment Operator */
RPN& RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		mStack = rhs.mStack;
	}
	return (*this);
}

/* Desturctor */
RPN::~RPN()
{}

void RPN::insertString(char* av)
{
	for (std::size_t i = 0; av[i]; ++i)
	{
		if (i % 2 == 0 && av[i] != ' ')
			insert(av[i]);
		else if (i % 2 == 1 && av[i] == ' ')
			continue;
		else
			throw RPN::ExpressionException();
	}
}

void	RPN::insert(char c)
{
	if (std::isdigit(static_cast<int>(c)))
	{
		push(c - '0');
		return ;
	}
	/* 숫자가 아닐 경우 내부 스택에 저장되어있는 숫자가 2개 미만일 경우 */
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
