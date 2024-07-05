/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:15:46 by janhan            #+#    #+#             */
/*   Updated: 2024/07/05 17:23:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	this->mName = name;
	std::cout << "[Constructed] : " << mName << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "[Destructed] : " << this->mName << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->mName << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
