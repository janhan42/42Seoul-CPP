/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:47:19 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 15:38:14 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->mName = "<NULL>";
	this->mHitPoint = 100;
	this->mEnergyPoint = 50;
	this->mAttackDamege = 20;
	std::cout << "[Constructor] : " << this->mName << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
{
	this->mName = name;
	this->mHitPoint = 100;
	this->mEnergyPoint = 50;
	this->mAttackDamege = 20;
	std::cout << "[Constructor] : " << this->mName << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	this->mName = other.mName;
	this->mHitPoint = other.mHitPoint;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamege = other.mAttackDamege;
	std::cout << "[Constructor] : " << this->mName << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	this->mName = other.mName;
	this->mHitPoint = other.mHitPoint;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamege = other.mAttackDamege;
	std::cout << "[Constructor] : " << this->mName << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[Dstructor] : " << this->mName << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->mEnergyPoint > 0 && this->mHitPoint > 0)
	{
		std::cout << "ScavTrap " << this->mName << " is now in Gate keeper mode!" << std::endl;
		this->mEnergyPoint--;
	}
	else
		std::cout << "ClapTrap " << this->mName << " can’t do anything!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->mEnergyPoint > 0 && this->mHitPoint > 0)
	{
		std::cout << "ScavTrap " << this->mName << " attacks "
		<< target << ", causing " << this->mAttackDamege << " points of damage!" << std::endl;
		this->mEnergyPoint--;
	}
	else
		std::cout << "ClapTrap " << this->mName << " can’t do anything!" << std::endl;
}
