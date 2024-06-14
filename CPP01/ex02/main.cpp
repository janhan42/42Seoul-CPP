/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:24:58 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 19:33:29 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string string("HI THIS IS BRAIN");

	std::string	*stringPTR = &string;
	std::string &stringPEF = string;

	std::cout << "&string:\t" << &string << std::endl;
	std::cout << "stringPTR:\t" << stringPTR << std::endl;
	std::cout << "&stringPEF:\t" << &stringPEF << std::endl << std::endl;

	std::cout << "string:\t\t" << string << std::endl;
	std::cout << "*stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "stringPEF:\t" << stringPEF << std::endl << std::endl;

	return (0);
}
