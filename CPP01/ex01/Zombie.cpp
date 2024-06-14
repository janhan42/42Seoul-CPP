/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:45:14 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 19:18:04 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "";
	std::cout << "[Constructed] : <null>" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "[Constructed] : " << this->_name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "[Destructed] : " << this->_name << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	std::cout << "This Zombie got name, " << name << std::endl;
}
