/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:53:16 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:17:44 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_name = "<NULL>";
	ClapTrap::mName = _name + "_clap_name";
	mHitPoint = FragTrap::mHitPoint;
	mEnergyPoint = ScavTrap::mEnergyPoint;
	mAttackDamage = FragTrap::mAttackDamage;
	std::cout << "[DiamondTrap Constructor] : " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	_name = name;
	ClapTrap::mName = name + "_clap_name";
	mHitPoint = FragTrap::mHitPoint;
	mEnergyPoint = ScavTrap::mEnergyPoint;
	mAttackDamage = FragTrap::mAttackDamage;
	std::cout << "[DiamondTrap Constructor by name] : " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other)
, ScavTrap(other)
, FragTrap(other)
{
	*this = other;
	std::cout << "[DiamondTrap Copy Constructor] : " << _name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		mHitPoint = other.mHitPoint;
		mEnergyPoint = other.mEnergyPoint;
		mAttackDamage = other.mAttackDamage;
	}
	std::cout << "[DiamondTrap Copy Assignment Constructor] : " << _name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap Destructor] : " << _name << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "=========WHO AM I=========" << std::endl
	<< "DiamondTrap Name: \t" << _name
			<< "\nClapTrap Name: \t\t" << ClapTrap::mName << std::endl
	<< "==========================" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::printStatus(void)
{
	std::cout
		<< "\nName:\t\t" << _name
		<< "\nHit Point:\t\t" << mHitPoint
		<< "\nEnergy Point\t" << mEnergyPoint
		<< "\nAttack damage:\t" << mAttackDamage
		<< std::endl << std::endl;
}
