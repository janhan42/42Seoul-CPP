/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:20:18 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:35:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	mName = "<NULL>";
	mHitPoint = 100;
	mEnergyPoint = 100;
	mAttackDamage = 30;
	std::cout << "[FragTrap Constructor] : " << mName << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
	mName = name;
	mHitPoint = 100;
	mEnergyPoint = 100;
	mAttackDamage = 30;
	std::cout << "[FragTrap Constructor by name] : " << mName << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	mName = other.mName;
	mHitPoint = other.mHitPoint;
	mEnergyPoint = other.mEnergyPoint;
	mAttackDamage = other.mAttackDamage;
	std::cout << "[FragTrap Copy Constructor] : " << mName << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		mName = other.mName;
		mHitPoint = other.mHitPoint;
		mEnergyPoint = other.mEnergyPoint;
		mAttackDamage = other.mAttackDamage;
	}
	std::cout << "[FragTrap Copy Assingment Constructor] : " << mName << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap Destructor] : " << mName << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (mEnergyPoint > 0 && mHitPoint > 0)
	{
		std::cout << "FragTrap " << mName << " positive high fives!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << mName << " can't do anything!" << std::endl;
	}
}
