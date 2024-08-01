/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:50:53 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:39:33 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();										/* Constructor */
		DiamondTrap(std::string name);						/* Constructor by name */
		DiamondTrap(const DiamondTrap& other);				/* Copy Constructor */
		DiamondTrap& operator=(const DiamondTrap& other);	/* Copy assignment Constructor */
		~DiamondTrap();										/* Destructor */

		void	whoAmI(void);
		void	attack(const std::string& target);
		void	printStatus(void);
	private:
		std::string _name;
};
