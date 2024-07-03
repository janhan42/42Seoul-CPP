/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:32:42 by janhan            #+#    #+#             */
/*   Updated: 2024/07/03 18:09:01 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string	cmd;
	PhoneBook	phone_book;

	while (cmd != "EXIT")
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
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
	}
	return (0);
}
