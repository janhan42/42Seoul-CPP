/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:37:13 by janhan            #+#    #+#             */
/*   Updated: 2024/08/29 20:42:38 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <exception>
#include <iostream>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base*	generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return (Base*)0;
}

void	identify(Base* ptr)
{
	if (dynamic_cast<A *>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unable to identify." << std::endl;
}

void	identify(Base& ptr)
{
	try
	{
		(void)dynamic_cast<A&>(ptr);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception&)
	{}
	try
	{
		(void)dynamic_cast<B&>(ptr);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception&)
	{}
	try
	{
		(void)dynamic_cast<C&>(ptr);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception&)
	{}
}

int main(void)
{
	std::srand(time(NULL));
	for (size_t i = 0; i < 20; ++i)
	{
		Base* ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
		ptr = NULL;
	}
	return 0;
}
