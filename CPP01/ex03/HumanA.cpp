/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:53:24 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 11:50:18 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
: mName(name)
, mWeapon(weapon)
{
	std::cout << "Human A " << mName << " created." << std::endl;
	std::cout << "Their wapon is : " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Human A " << mName << " destroyed." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << mName << " attacks whit their " << mWeapon.getType() << std::endl;
}
