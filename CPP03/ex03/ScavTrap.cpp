/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:47:19 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:01:36 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	mName = "<NULL>";
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 20;
	std::cout << "[Scav Trap Constructor] : " << mName << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
{
	mName = name;
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 20;
	std::cout << "[Scav Trap Constructor by name] : " << mName << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	mName = other.mName;
	mHitPoint = other.mHitPoint;
	mEnergyPoint = other.mEnergyPoint;
	mAttackDamage = other.mAttackDamage;
	std::cout << "[Scav Trap Copy Constructor] : " << mName << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		mName = other.mName;
		mHitPoint = other.mHitPoint;
		mEnergyPoint = other.mEnergyPoint;
		mAttackDamage = other.mAttackDamage;
	}
	std::cout << "[Scav Trap Copy Assignment Constructor] : " << mName << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[Scav Trap Destructor] : " << mName << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (mEnergyPoint > 0 && mHitPoint > 0)
	{
		std::cout << "ScavTrap " << mName << " is now in Gate keeper mode!" << std::endl;
		mEnergyPoint--;
	}
	else
		std::cout << "ScavTrap " << mName << " can’t do anything!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (mEnergyPoint > 0 && mHitPoint > 0)
	{
		std::cout << "ScavTrap " << mName << " attacks "
		<< target << ", causing " << mAttackDamage << " points of damage!" << std::endl;
		mEnergyPoint--;
	}
	else
		std::cout << "ScavTrap " << mName << " can’t do anything!" << std::endl;
}
