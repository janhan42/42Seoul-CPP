/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:08:50 by janhan            #+#    #+#             */
/*   Updated: 2024/07/25 15:59:54 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		void				SetFirstName(const std::string& firstName);
		void				SetLastName(const std::string& lastName);
		void				SetNickName(const std::string& nickName);
		void				SetPhoneNumber(const std::string& phoneNumber);
		void				SetSecret(const std::string& secret);
		const std::string&	GetFirstName(void) const;
		const std::string&	GetLastName(void) const;
		const std::string&	GetNickName(void) const;
		const std::string&	GetPhoneNumber(void) const;
		const std::string&	GetSecret(void) const;
	private:
		std::string			mFirstName;
		std::string			mLastName;
		std::string			mNickName;
		std::string			mPhoneNumber;
		std::string			mSecret;
};

#endif
