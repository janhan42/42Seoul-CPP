/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:37:57 by janhan            #+#    #+#             */
/*   Updated: 2024/09/09 08:44:01 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange exc;
	try
	{
		exc.importDataBase(std::string("./data.csv"));
		exc.exchange(std::string(av[1]));
		for (std::list<std::string>::const_iterator it = exc.getExchangeResult().begin();
			it != exc.getExchangeResult().end(); ++it)
			std::cout << *it << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
