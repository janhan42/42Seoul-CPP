/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:20:18 by janhan            #+#    #+#             */
/*   Updated: 2024/07/08 14:36:41 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->mName = "<NULL>";
	this->mHitPoint = 100;
	this->mEnergyPoint = 100;
	this->mAttackDamege = 30;
	std::cout << "FragTrap constructor : " << this->mName << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
	this->mName = name;
	this->mHitPoint = 100;
	this->mEnergyPoint = 100;
	this->mAttackDamege = 30;
	std::cout << "FragTrap constructor : " << this->mName << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	this->mName = other.mName;
	this->mHitPoint = other.mHitPoint;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamege = other.mAttackDamege;
	std::cout << "FragTrap constructor : " << this->mName << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	this->mName = other.mName;
	this->mHitPoint = other.mHitPoint;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamege = other.mAttackDamege;
	std::cout << "FragTrap constructor : " << this->mName << std::endl;
	return (*this);
}


FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor : " << this->mName << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->mEnergyPoint > 0 && this->mHitPoint > 0)
	{
		std::cout << "FragTrap " << this->mName << " positive high fives!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->mName << " can't do anything!" << std::endl;
	}
}
