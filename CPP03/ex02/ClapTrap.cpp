/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:04:01 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:30:00 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: mHitPoint(10)
, mEnergyPoint(10)
, mAttackDamage(0)
{
	mName = "<NULL>";
	std::cout << "[ClapTrap Constructor] : " << mName << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: mName(name)
, mHitPoint(10)
, mEnergyPoint(10)
, mAttackDamage(0)
{
	std::cout << "[ClapTrap Constructor by name] : " << mName << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
: mName(other.mName)
, mHitPoint(other.mHitPoint)
, mEnergyPoint(other.mEnergyPoint)
, mAttackDamage(other.mAttackDamage)
{
	std::cout << "[ClapTrap Copy Constructor] : " << mName << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		mName = other.mName;
		mHitPoint = other.mHitPoint;
		mEnergyPoint = other.mEnergyPoint;
		mAttackDamage = other.mAttackDamage;
	}
	std::cout << "[ClapTrap Copy Assingment Constructor] : " << mName << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap Dstructor] : " << mName << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (mEnergyPoint > 0 && mHitPoint > 0)
	{
		std::cout << "ClapTrap " << mName << " attacks "
		<< target << ", causing " << mAttackDamage << " points of damage!" << std::endl;
		mEnergyPoint--;
	}
	else
		std::cout << "ClapTrap " << mName << " can’t do anything!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (mHitPoint < amount)
		mHitPoint = 0;
	else
		mHitPoint -= amount;
	std::cout << "ClapTrap " << mName << " has taken " << amount
				<< " damages! " << mHitPoint << " HP left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (mEnergyPoint > 0 && mHitPoint > 0)
	{
		mHitPoint += amount;
		mEnergyPoint--;
		std::cout << "ClapTrap " << mName << " is repaired, gets HP "
			<< amount << " and now HP is " << mHitPoint << std::endl;
	}
	else
		std::cout << "ClapTrap " << mName << " can’t do anything!" << std::endl;
}
