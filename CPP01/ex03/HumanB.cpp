/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:59:34 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 23:02:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	_Weapon = NULL;
	std::cout << "Human B " << this->_name << " created." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Human B " << this->_name << " destroyed." << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_Weapon == NULL)
		std::cout << this->_name << " cannot attack: weapon is missing." << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_Weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_Weapon = &weapon;
}
