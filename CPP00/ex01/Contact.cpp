/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:15:09 by janhan            #+#    #+#             */
/*   Updated: 2024/07/03 18:58:12 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void	Contact::SetFirstName(const std::string& firstName)
{
	this->mFirstName = firstName;
}

void	Contact::SetLastName(const std::string& lastName)
{
	this->mLastName = lastName;
}

void	Contact::SetNickName(const std::string& nickName)
{
	this->mNickName = nickName;
}

void	Contact::SetPhoneNumber(const std::string& phoneNumber)
{
	this->mPhoneNumber = phoneNumber;
}

void	Contact::SetSecret(const std::string& secret)
{
	this->mSecret = secret;
}

const std::string	Contact::GetFirstName() const
{
	return (this->mFirstName);
}

const std::string Contact::GetLastName() const
{
	return (this->mLastName);
}

const std::string Contact::GetNickName() const
{
	return (this->mNickName);
}

const std::string Contact::GetPhoneNumber() const
{
	return (this->mPhoneNumber);
}

const std::string Contact::GetSecret() const
{
	return (this->mSecret);
}
