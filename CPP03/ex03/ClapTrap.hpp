/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:58:57 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:39:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();										/* Constructor */
		ClapTrap(const std::string name);				/* Constructor by name */
		ClapTrap(const ClapTrap& other);				/* Copy Constructor */
		ClapTrap &operator=(const ClapTrap& other);		/* Copy assignment Constructor */
		virtual ~ClapTrap();							/* Destructor */

		virtual void			attack(const std::string& target);
		void					takeDamage(unsigned int amount);
		void					beRepaired(unsigned int amount);
	protected:
		std::string				mName;
		unsigned int			mHitPoint;
		unsigned int			mEnergyPoint;
		unsigned int			mAttackDamage;
};
