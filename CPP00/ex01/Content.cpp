/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Content.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:15:09 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 08:12:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Content.hpp"

Content::Content()
{}

Content::~Content()
{}

void	Content::set_frist_name(std::string first_name)
{
	this->_first_name = first_name;
}

void	Content::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void	Content::set_nick_name(std::string nick_name)
{
	this->_nick_name = nick_name;
}

void	Content::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Content::set_secret(std::string secret)
{
	this->_secret = secret;
}

std::string	Content::get_first_name() const
{
	return (this->_first_name);
}

std::string Content::get_last_name() const
{
	return (this->_last_name);
}

std::string Content::get_nick_name() const
{
	return (this->_nick_name);
}

std::string Content::get_phone_number() const
{
	return (this->_phone_number);
}

std::string Content::get_secret() const
{
	return (this->_secret);
}
