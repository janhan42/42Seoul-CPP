/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:04:01 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 09:38:38 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
: mHitPoint(10)
, mEnergyPoint(10)
, mAttackDamege(0)
{
	mName = "<NULL>";
	std::cout << "[Constructor] : " << this->mName << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: mName(name)
, mHitPoint(10)
, mEnergyPoint(10)
, mAttackDamege(0)
{
	std::cout << "[Constructor] : " << this->mName << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->mName = other.mName;
	this->mHitPoint = other.mHitPoint;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamege = other.mAttackDamege;
	std::cout << "[Constructor] : " << this->mName << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->mName = other.mName;
	this->mHitPoint = other.mHitPoint;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamege = other.mAttackDamege;
	std::cout << "[Constructor] : " << this->mName << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[Dstructor] : " << this->mName << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->mEnergyPoint > 0 && this->mHitPoint > 0)
	{
		std::cout << "ClapTrap " << this->mName << "attacks "
		<< target << ", causing " << this->mAttackDamege << " points of damage!" << std::endl;
		this->mEnergyPoint--;
	}
	else
		std::cout << "ClapTrap " << this->mName << " can’t do anything!" << std::endl;
}

void	ClapTrap::takeDamege(unsigned int amount)
{
	if (this->mHitPoint < amount)
		this->mHitPoint = 0;
	else
		this->mHitPoint -= amount;
	std::cout << "ClapTrap " << this->mName << " has taken " << amount
				<< " damages! " << this->mHitPoint << " HP left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->mEnergyPoint > 0 && this->mHitPoint > 0)
	{
		mHitPoint += amount;
		mEnergyPoint--;
		std::cout << "ClapTrap " << this->mName << " is repaired, gets HP "
			<< amount << " and now HP is " << this->mHitPoint << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->mName << " can’t do anything!" << std::endl;
}
