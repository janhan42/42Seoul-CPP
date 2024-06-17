/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:53:24 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 22:56:16 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _Weapon(weapon)
{
	std::cout << "Human A " << this->_name << " created." << std::endl;
	std::cout << "Their wapon is : " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Human A " << this->_name << " destroyed." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks whit their " << this->_Weapon.getType() << std::endl;
}
