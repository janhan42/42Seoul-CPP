/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:20:14 by janhan            #+#    #+#             */
/*   Updated: 2024/07/03 07:49:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <iomanip>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	Add();
		void	ShowContacts();
		void	ShowContactByIndex(int index);
		int		GetCount() const;

	private:
		Contact	mContacts[8];
		int		mIndex;
		int		mCount;
		void	printValue(std::string str);
		void	printContact(int index);
};
#endif
