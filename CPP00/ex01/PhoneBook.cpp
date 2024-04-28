/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:23:29 by janhan            #+#    #+#             */
/*   Updated: 2024/04/25 07:43:48 by janhan           ###   ########.fr       */
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

void	PhoneBook::_print_value(std::string str)
{
	int	len = str.length();
	for (int i = 0; i < 10 - len; i++)
		std::cout << " ";
	if (len <= 10)
		std::cout << str;
	else
		std::cout << str.substr(0, 9) << '.';
	std::cout << "|";
}

void	PhoneBook::_print_content(int index)
{
	std::cout << "|         " << index << "|";
	this->_print_value(this->_content[index].get_first_name());
	this->_print_value(this->_content[index].get_last_name());
	this->_print_value(this->_content[index].get_nick_name());
	std::cout << "\n";
}

void	PhoneBook::show_content()
{
	std::cout
		<< "┌──────────┬──────────┬──────────┬──────────┐\n"
		<< "│   Index  │First name│ Last name│ Nickname │\n"
		<< "├──────────┼──────────┼──────────┼──────────┤\n";
		std::cout << "\n";
	if (this->_count == 0)
		std::cout
			<< "│         -│         -│         -│         -│\n"
			<< "└──────────┴──────────┴──────────┴──────────┘\n";
	else
	{
		for (int i = 0; i < this->_count; i++)
		{
			this->_print_content(i);
			if (i + 1 != this->_count)
				std::cout
					<<"├──────────┼──────────┼──────────┼──────────┤\n";
		}
		std::cout
			<< "└──────────┴──────────┴──────────┴──────────┘\n";
	}
}

void	PhoneBook::shon_content_by_index(int index)
{
	if ((0 <= index && index <= 7) == false)
	{
		std::cout << "Wrong index." << std::endl;
		return ;
	}
	if (index >= _count)
	{
		std::cout << "Wrong index." << std::endl;
		return ;
	}
	std::cout	<< '\n'
				<< "First name: " << _content[index].get_first_name() << '\n'
				<< "Last name: " << _content[index].get_last_name() << '\n'
				<< "Nick name: " << _content[index].get_nick_name() << '\n'
				<< "Secret: " << _content[index].get_secret() << '\n'
				<< "Phone number: " << _content[index].get_phone_number() << '\n'
				<< std::endl;
}

int	PhoneBook::get_count() const
{
	return this->_count;
}
