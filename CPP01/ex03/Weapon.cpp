/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:49:20 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 11:50:26 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& name)
: mType(name)
{
	std::cout << "Weapon " << mType << " created." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << mType << " destroyed." << std::endl;
}

void	Weapon::setType(const std::string& type)
{
	mType = type;
}

const std::string& Weapon::getType(void) const
{
	return (mType);
}
