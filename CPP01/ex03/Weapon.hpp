/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:47:37 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 11:49:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

/*

	Implement a Weapon class that has:

	- A private atrribute type, which is a string.
	- A getType() member function that retyrns a const reference type.
	- A setType() member function that sets type using
	the new one passed as param-eter.

 */

class Weapon
{
	public:
		Weapon(const std::string& name);
		~Weapon();

		const std::string&	getType(void) const;
		void				setType(const std::string& type);
	private:
		std::string mType;
};

#endif
