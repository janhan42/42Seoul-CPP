/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:32:42 by janhan            #+#    #+#             */
/*   Updated: 2024/04/25 07:41:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

int main()
{
	std::string	cmd;
	PhoneBook	phone_book;

	while (cmd != "EXIT")
	{
		std::cout << "Command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phone_book.add();
		else if (cmd == "SEARCH")
		{
			phone_book.show_content();
			std::cout << "Index: ";
			std::getline(std::cin, cmd);
			if (cmd.size() == 1 && ('0' <= cmd[0] && cmd[0] <= '9'))
				phone_book.shon_content_by_index(cmd[0] - '0');
			else
				std::cout << "Wrong format." << std::endl;
		}
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
