/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:47:19 by janhan            #+#    #+#             */
/*   Updated: 2024/08/05 07:19:12 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

/* Constructor */
ScavTrap::ScavTrap()
{
	mName = "<NULL>";
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 20;
	std::cout << "[ScavTrap Constructor] : " << mName << std::endl;
}

/* Constructor by name */
ScavTrap::ScavTrap(const std::string& name)
{
	mName = name;
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 20;
	std::cout << "[ScavTrap Constructor by name] : " << mName << std::endl;
}

/* Copy Constructor */
ScavTrap::ScavTrap(const ScavTrap& other)
{
	mName = other.mName;
	mHitPoint = other.mHitPoint;
	mEnergyPoint = other.mEnergyPoint;
	mAttackDamage = other.mAttackDamage;
	std::cout << "[ScavTrap Copy Constructor] : " << mName << std::endl;
}

/* Copy Assignment Operator */
ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		mName = other.mName;
		mHitPoint = other.mHitPoint;
		mEnergyPoint = other.mEnergyPoint;
		mAttackDamage = other.mAttackDamage;
	}
	std::cout << "[ScavTrap Copy Assingment Constructor] : " << mName << std::endl;
	return (*this);
}

/* Destructor */
ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap Dstructor] : " << mName << std::endl;
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
