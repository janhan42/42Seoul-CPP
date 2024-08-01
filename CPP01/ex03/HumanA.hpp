/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:51:39 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 11:50:07 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

/*
	Now, create two classes: HumanA and HumanB.
	They both have a Weapon and a name.
	They also have a member function attack() that display
	(of course, without the angle brackets):

	<name> attack with their <weapon type>

	HumanA and HumanB are almost the same except for thes tow tiny details:

	- While HumanA takes the Weapon in its constructor, HumanB doesn't.
	- HumanB may not always have a Weapon, whereas HumanA will always be armed.
 */

class HumanA
{
	public:
		HumanA(const std::string& name, Weapon& weapon);	/* Constructor */
		~HumanA();											/* Destructor */

		void	attack(void);								/* Subject function */
	private:
		std::string	mName;									/* Member Name */
		Weapon&		mWeapon;								/* Member Weapon */
		/* 레퍼런스 타입은 생성과 동시에 초기화 해줘야하는 점을 이용해서 A는 항상 무기를 들고있다 */
};

#endif
