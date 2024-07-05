/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:49:20 by janhan            #+#    #+#             */
/*   Updated: 2024/07/05 16:01:47 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	setType(name);
	std::cout << "Weapon " << mType << " created." << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon " << mType << " destroyed." << std::endl;
}

void	Weapon::setType(std::string type)
{
	this->mType = type;
}

const std::string& Weapon::getType() const
{
	return (this->mType);
}
