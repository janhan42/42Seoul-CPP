/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:53:24 by janhan            #+#    #+#             */
/*   Updated: 2024/07/05 15:59:58 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : mName(name), mWeapon(weapon)
{
	std::cout << "Human A " << this->mName << " created." << std::endl;
	std::cout << "Their wapon is : " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Human A " << this->mName << " destroyed." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->mName << " attacks whit their " << this->mWeapon.getType() << std::endl;
}
