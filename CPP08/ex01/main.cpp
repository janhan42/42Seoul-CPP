/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:31:21 by janhan            #+#    #+#             */
/*   Updated: 2024/09/05 09:38:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(1);
		sp.addNumber(22);
		sp.addNumber(43);
		sp.addNumber(4);
		std::cout << "span shortesSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "span longestSpan : " << sp.longestSpan() << std::endl << std::endl;
	}

	{
		Span sp(3);
		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MAX / 10);
		std::cout << "span shortesSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "span longestSpan : " << sp.longestSpan() << std::endl << std::endl;
	}

	{
		std::srand(static_cast<unsigned int>(time(NULL)));
		std::vector<int> vec;
		for (std::size_t i = 0; i < 10000; ++i)
			vec.push_back(std::rand());
		Span sp(10000);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << "span shortesSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "span longestSpan : " << sp.longestSpan() << std::endl;
	}
}
