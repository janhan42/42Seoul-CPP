/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:23:29 by janhan            #+#    #+#             */
/*   Updated: 2024/04/24 21:46:16 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_count = 0;
}

PhoneBook::~PhoneBook()
{}

void	PhoneBook::add()
{
	std::string str;

	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "First name: ";
		std::getline(std::cin, str);
		if (str != "")
			this->_content[this->_index].set_frist_name(str);
	}
	str = "";
	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, str);
		if (str != "")
			this->_content[this->_index].set_last_name(str);
	}
	str = "";
	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "Nick name: ";
		std::getline(std::cin, str);
		if (str != "")
			this->_content[this->_index].set_nick_name(str);
	}
	str = "";
	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, str);
		if (str != "")
			this->_content[this->_index].set_phone_number(str);
	}
	str = "";
	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "Secret: ";
		std::getline(std::cin, str);
		if (str != "")
			this->_content[this->_index].set_secret(str);
	}
	if (this->_count != 8)
		this->_count++;
	this->_index++;
	if (this->_index == 8)
		this->_index = 0;
}
