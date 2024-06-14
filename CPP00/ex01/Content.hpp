/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Content.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:08:50 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 08:12:33 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTENT_HPP
# define CONTENT_HPP

#include <string>

class Content
{
	public:
		Content();
		~Content();
		void	set_frist_name(std::string first_name);
		void	set_last_name(std::string last_name);
		void	set_nick_name(std::string nick_name);
		void	set_phone_number(std::string phone_number);
		void	set_secret(std::string secret);
		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nick_name() const;
		std::string	get_phone_number() const;
		std::string	get_secret() const;
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_secret;
};
#endif
