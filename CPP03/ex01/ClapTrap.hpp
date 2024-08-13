/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:58:57 by janhan            #+#    #+#             */
/*   Updated: 2024/08/07 18:40:38 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

/*

	First, you have to implement a class! How original!

	It will be called ClapTrap and will have the following private auttributes initialized
	to the value specified in brackets:

		- Name, which is passed as parameter to a constructor
		- Hit point (10), represent the health of the ClapTrap
		- Energy points (10)
		- Attack damage (0)

	Add the follwing public member functions so the ClapTrap looks more realistic:

		- void attack(const sts::string& target);
		- void takeDamage(unsigned int amount);
		- void beRepaired(unsigned int amount);

	When ClapTrap attackes, it causes its target to lose <attack damage> hit points.
	When ClapTrap repairs itself, it gets <amount> hit points back, Attacking and repairing
	cost 1 energy point each. Of course, ClapTrap cat't do anything if it has no hit points
	or energy points left.

	In all of these member functions, yoy have to print a meaasge to describe what hap-pens.
	For example, the attcak() function may display something like(of course, wihout the angle
	brackets):

		ClapTrap <name> attacks <target>, causing <damage> points of damage!

	The constructors and destructor must also display a message, so your peer-evaluators
	can esily see they have been called.

	Implement and turn in your own tests to ensure your code works as expected.

 */

class ClapTrap
{
	public:
		ClapTrap();											/* Constructor */
		ClapTrap(const std::string name);					/* Constructor by name */
		ClapTrap(const ClapTrap& other);					/* Copy Constructor */
		ClapTrap &operator=(const ClapTrap& other);			/* Copy Assingment Constructor */
		virtual ~ClapTrap();								/* Destructor */

		virtual void	attack(const std::string& target);	/* Subject attack() function */
		void			takeDamage(unsigned int amount);	/* Subject takeDamage() function */
		void			beRepaired(unsigned int amount);	/* Subject beRepaired() function */

	protected:												/* private -> protected */
		std::string		mName;								/* ClapTrap Name */
		unsigned int	mHitPoint;							/* ClapTrap Hit Point */
		unsigned int	mEnergyPoint;						/* ClapTrap Energy Point */
		unsigned int	mAttackDamage;						/* ClapTrap Attack Damamge */
};
