/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:49:20 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 22:54:46 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	setType(name);
	std::cout << "Weapon " << _type << " created." << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon " << _type << " destroyed." << std::endl;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const& Weapon::getType() const
{
	return (this->_type);
}
