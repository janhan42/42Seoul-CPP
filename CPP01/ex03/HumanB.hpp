/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:56:25 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 11:16:49 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

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

class HumanB
{
	public:
		HumanB(const std::string& name);		/* Constructor */
		~HumanB(void);							/* Destrucotr */

		void	attack(void);					/* Subject Function */
		void	setWeapon(Weapon& weapon);		/* HunmanB Weapon Setter */

	private:
		std::string mName;						/* Member Name */
		Weapon*		mWeapon;					/* Member Weapon */
		/* B는 포인터를 이용해서 처음에는 무기를 NULL로 설정해서 무장하지 않고 이후 setWeapon을 이용해서 설정해준다 */
};

#endif
