/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:23:29 by janhan            #+#    #+#             */
/*   Updated: 2024/07/25 15:54:01 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>


PhoneBook::PhoneBook()
{
	this->mIndex = 0;
	this->mCount = 0;
}

PhoneBook::~PhoneBook()
{}

void	PhoneBook::Add(void)
{
	std::string str;

	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "First name: ";
		std::getline(std::cin, str);
		if (isOnlySpace(str) == true)
		{
			std:: cout << "contact can't have empty fields." << std::endl;
			str = "";
		}
		else if (isNonPrintable(str) == true)
		{
			std::cout << "contact cat't have Non Printable charactor." << std::endl;
			str = "";
		}
		if (str != "")
			this->mContacts[this->mIndex].SetFirstName(str);
	}
	str = "";
	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, str);
		if (isOnlySpace(str) == true)
		{
			std:: cout << "contact can't have empty fields." << std::endl;
			str = "";
		}
		else if (isNonPrintable(str) == true)
		{
			std::cout << "contact cat't have Non Printable charactor." << std::endl;
			str = "";
		}
		if (str != "")
			this->mContacts[this->mIndex].SetLastName(str);
	}
	str = "";
	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "Nick name: ";
		std::getline(std::cin, str);
		if (isOnlySpace(str) == true)
		{
			std:: cout << "contact can't have empty fields." << std::endl;
			str = "";
		}
		else if (isNonPrintable(str) == true)
		{
			std::cout << "contact cat't have Non Printable charactor." << std::endl;
			str = "";
		}
		if (str != "")
			this->mContacts[this->mIndex].SetNickName(str);
	}
	str = "";
	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, str);
		if (isOnlySpace(str) == true)
		{
			std:: cout << "contact can't have empty fields." << std::endl;
			str = "";
		}
		else if (isNonPrintable(str) == true)
		{
			std::cout << "contact cat't have Non Printable charactor." << std::endl;
			str = "";
		}
		if (str != "")
			this->mContacts[this->mIndex].SetPhoneNumber(str);
	}
	str = "";
	while (str == "" && std::cin.eof() == false)
	{
		std::cout << "Secret: ";
		std::getline(std::cin, str);
		if (isOnlySpace(str) == true)
		{
			std:: cout << "contact can't have empty fields." << std::endl;
			str = "";
		}
		else if (isNonPrintable(str) == true)
		{
			std::cout << "contact cat't have Non Printable charactor." << std::endl;
			str = "";
		}
		if (str != "")
			this->mContacts[this->mIndex].SetSecret(str);
	}
	if (this->mCount != 8)
		this->mCount++;
	mIndex = (mIndex + 1 % 8);
}

void	PhoneBook::ShowContacts(void)
{
	std::cout
			<< "┌──────────┬──────────┬──────────┬──────────┐\n"
			<< "│     Index│First name│ Last name│  Nickname│\n"
			<< "├──────────┼──────────┼──────────┼──────────┤\n";
	if (this->mCount == 0)
		std::cout
			<< "│         -│         -│         -│         -│\n"
			<< "└──────────┴──────────┴──────────┴──────────┘\n";
	else
	{
		for (int i = 0; i < this->mCount; i++)
		{
			this->printContact(i);
			if (i + 1 != this->mCount)
				std::cout
					<< "├──────────┼──────────┼──────────┼──────────┤\n";
		}
		std::cout
			<< "└──────────┴──────────┴──────────┴──────────┘\n";
	}
}


void	PhoneBook::ShowContactByIndex(int index)
{
	if (((0 <= index && index <= 7) == false) || index >= mCount)
	{
		std::cout << "Wrong index." << std::endl;
		return ;
	}
	std::cout << '\n'
			<< "First name:       "<< mContacts[index].GetFirstName() << '\n'
			<< "Last name:        "<< mContacts[index].GetLastName() << '\n'
			<< "Nickname:         "<< mContacts[index].GetNickName() << '\n'
			<< "Darkest secret:   "<< mContacts[index].GetSecret() << '\n'
			<< "Phone number:     "<< mContacts[index].GetPhoneNumber() << '\n'
			<< std::endl;
}

void	PhoneBook::printValue(std::string str)
{
	int	str_len = str.length();
	if (str_len <= 10)
		std::cout << std::setfill(' ') << std::setw(10) << str;
	else
		std::cout << std::setfill(' ' ) << std::setw(9) << str.substr(0, 9) << '.';
	std::cout << "|";
}

void	PhoneBook::printContact(int index)
{
	std::cout << "|         " << index << "|";
	this->printValue(this->mContacts[index].GetFirstName());
	this->printValue(this->mContacts[index].GetLastName());
	this->printValue(this->mContacts[index].GetNickName());
	std::cout << "\n";
}

bool	PhoneBook::isOnlySpace(const std::string& str) const
{
	int	str_len = str.size();

	for (int i = 0; i < str_len; i++)
	{
		if (std::isspace(str[i]) == false)
			return (false);
	}
	return (true);
}

bool	PhoneBook::isNonPrintable(const std::string& str) const
{
	int	str_len = str.size();

	for (int i = 0; i < str_len; i++)
	{
		if (std::isprint(str[i]) == false)
			return (true);
	}
	return (false);
}
