/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:53:16 by janhan            #+#    #+#             */
/*   Updated: 2024/07/08 15:08:03 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->_name = "<NULL>";
	ClapTrap::mName ="<NULL>_clap_name";
	this->mHitPoint = FragTrap::mHitPoint;
	this->mEnergyPoint = 50;
	this->mAttackDamege = FragTrap::mAttackDamege;
	std::cout << "DiamondTrap constructor : " << this->mName << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->mName = name;
	ClapTrap::mName = name + "_clap_name";
	this->mHitPoint = FragTrap::mHitPoint;
	this->mEnergyPoint = 50;
	this->mAttackDamege = FragTrap::mAttackDamege;
	std::cout << "DiamondTrap constructor : " << this->mName << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other)
, ScavTrap(other)
, FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap constructor : " << this->mName << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other)
{
	this->_name = other._name;
	this->mHitPoint = other.mHitPoint;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamege = other.mAttackDamege;
	std::cout << "DiamondTrap constructor " << this->_name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor: " << this->_name << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap Name: \t" << this->_name
			<< "\nClapTrap Name: \t" << ClapTrap::mName << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::printStatus(void)
{
	std::cout
		<< "\nName:\t\t" << _name
		<< "\nHit Point:\t" << mHitPoint
		<< "\nEnergy Point\t" << mEnergyPoint
		<< "\nAttack damage:\t" << mAttackDamege
		<< std::endl << std::endl;
}
