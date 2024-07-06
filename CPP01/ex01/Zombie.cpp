/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:45:14 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 09:36:10 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->mName = "";
	std::cout << "[Constructed] : <null>" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->mName = name;
	std::cout << "[Constructed] : " << this->mName << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "[Destructed] : " << this->mName << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->mName << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->mName = name;
	std::cout << "This Zombie got name, " << name << std::endl;
}
