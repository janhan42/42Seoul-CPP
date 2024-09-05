/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:36:30 by janhan            #+#    #+#             */
/*   Updated: 2024/09/05 08:07:19 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <limits>

Span::Span(unsigned int capacity)
: mCapacity(capacity)
, mNumbers(std::vector<int>())
{}

Span::Span(const Span& rhs)
: mCapacity(rhs.mCapacity)
, mNumbers(rhs.mNumbers)
{}

Span& Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		mCapacity = rhs.mCapacity;
		mNumbers = rhs.mNumbers;
	}
	return (*this);
}

Span::~Span()
{}

void Span::addNumber(int number)
{
	if (mNumbers.size() == mCapacity)
		throw std::exception();
	mNumbers.push_back(number);
}

unsigned int Span::shortestSpan(void) const
{
	if (mNumbers.size() <= 1)
		throw std::exception();
	std::vector<int> copy(mNumbers);
	std::sort(copy.begin(), copy.end());
	unsigned int result = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); ++it)
	{
		result = std::min(result, static_cast<unsigned int>(*(it + 1) - *it));
		if (result == 0)
			return result;
	}
	return result;
}

unsigned int Span::longestSpan(void) const
{
	if (mNumbers.size() <= 1)
		throw std::exception();
	int min = std::numeric_limits<int>::max();
	int	max = std::numeric_limits<int>::min();
	for (std::vector<int>::const_iterator it = mNumbers.begin(); it != mNumbers.end(); ++it)
	{
		if (min > *it)
			min = *it;
		if (max < *it)
			max = *it;
	}
	return (static_cast<unsigned int>(max - min));
}
