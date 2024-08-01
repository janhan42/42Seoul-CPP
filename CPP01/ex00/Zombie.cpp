/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:15:46 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 11:40:17 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
: mName("<NULL>")
{
	std::cout << "[Constructor] : " << mName << std::endl;
}

Zombie::Zombie(const std::string& name)
: mName(name)
{
	std::cout << "[Constructor by name] : " << mName << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "[Destructor] : " << mName << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
