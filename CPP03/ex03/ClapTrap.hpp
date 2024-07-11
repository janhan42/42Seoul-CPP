/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:58:57 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 14:14:56 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap& other);
		virtual ~ClapTrap(void);

		virtual void			attack(const std::string& target);
		void					takeDamege(unsigned int amount);
		void					beRepaired(unsigned int amount);
	protected:
		std::string				mName;
		unsigned int			mHitPoint;
		unsigned int			mEnergyPoint;
		unsigned int			mAttackDamege;
};
