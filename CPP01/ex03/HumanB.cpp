/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:59:34 by janhan            #+#    #+#             */
/*   Updated: 2024/07/05 16:00:41 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : mName(name)
{
	mWeapon = NULL;
	std::cout << "Human B " << this->mName << " created." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Human B " << this->mName << " destroyed." << std::endl;
}

void	HumanB::attack(void)
{
	if (this->mWeapon == NULL)
		std::cout << this->mName << " cannot attack: weapon is missing." << std::endl;
	else
		std::cout << this->mName << " attacks with their " << this->mWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->mWeapon = &weapon;
}
