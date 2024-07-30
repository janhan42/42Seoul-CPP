/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:45:14 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 10:38:40 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
: mName("<null>")
{

	std::cout << "[Constructed] : "<< mName << std::endl;
}

Zombie::Zombie(const std::string& name)
: mName(name)
{
	std::cout << "[Constructed] : " << mName << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "[Destructed] : " << mName << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	mName = name;
	std::cout << "This Zombie got name, " << name << std::endl;
}
