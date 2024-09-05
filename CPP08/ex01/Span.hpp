/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:36:01 by janhan            #+#    #+#             */
/*   Updated: 2024/09/04 18:36:09 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
	public:
		Span(unsigned int capacity);
		Span(const Span& rhs);
		Span& operator=(const Span& rhs);
		~Span();

		void				addNumber(int number);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;

		template<typename It>
		void addNumber(It begin, It end)
		{
			while (begin != end)
				addNumber(*begin++);
		}
	private:
		unsigned int		mCapacity;
		std::vector<int>	mNumbers;
};

#endif
