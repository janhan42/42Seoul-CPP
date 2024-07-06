/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:32:42 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 05:48:34 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string	cmd;
	PhoneBook	phone_book;

	while (1)
	{
		std::cout << "usage: ADD SEARCH EXIT" << std::endl;
		std::cout << "Command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phone_book.Add();
		else if (cmd == "SEARCH")
		{
			phone_book.ShowContacts();
			std::cout << "Index: ";
			std::getline(std::cin, cmd);
			if (cmd.size() == 1 && ('0' <= cmd[0] && cmd[0] <= '9'))
				phone_book.ShowContactByIndex(cmd[0] - '0');
			else
				std::cout << "Wrong format." << std::endl;
		}
		else if (cmd == "EXIT")
			break ;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
	}
	return (0);
}
