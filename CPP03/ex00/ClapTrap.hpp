/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:58:57 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 09:27:48 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap& other);
		~ClapTrap(void);

		void			attack(const std::string& target);
		void			takeDamege(unsigned int amount);
		void			beRepaired(unsigned int amount);
	private:
		std::string		mName;
		unsigned int	mHitPoint;
		unsigned int	mEnergyPoint;
		unsigned int	mAttackDamege;
};