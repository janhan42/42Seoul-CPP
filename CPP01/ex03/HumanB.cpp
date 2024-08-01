/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:59:34 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 11:50:22 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
: mName(name)
{
	mWeapon = NULL;
	std::cout << "Human B " << mName << " created." << std::endl;
	std::cout << mName << " Weapon is" << "not armed" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Human B " << mName << " destroyed." << std::endl;
}

void	HumanB::attack(void)
{
	if (mWeapon == NULL)
		std::cout << mName << " cannot attack: weapon is missing." << std::endl;
	else
		std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	mWeapon = &weapon;
}
