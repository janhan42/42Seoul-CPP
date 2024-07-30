/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:24:58 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 10:59:05 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
	Write a program that contains:

	- A string variable initialized to "HI THIS IS BRAIN".
	- stringPTR: A pointer to the string
	- stringREF: A reference to the string

	Your program has to pring:

	- The memory address of the string variable
	- The memory address held by stringPTR
	- The memory address held by stringREF

	And then:

	- The value of the string variable
	- The value pointed to by stringPTR
	- The value pointed to by stringREF
 */

int main(void)
{
	/*  ==== contains ====  */
	std::string string("HI THIS IS BRAIN");
	std::string	*stringPTR = &string;
	std::string &stringPEF = string;
	/* ==== ========= ==== */

	std::cout << "==== The memory address ====" << std::endl;
	std::cout << "string:\t\t" << &string << std::endl;
	std::cout << "stringPTR:\t" << stringPTR << std::endl;
	std::cout << "stringPEF:\t" << &stringPEF << std::endl
	<< "====     ==========     ====" << std::endl << std::endl;

	std::cout << "======== The value ========" << std::endl;
	std::cout << "string:\t\t" << string << std::endl;
	std::cout << "stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "stringPEF:\t" << stringPEF << std::endl
	<< "====     =========     ====" << std::endl;

	return (0);
}
