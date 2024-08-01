/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:43:08 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:38:53 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();									/* Constructor */
		ScavTrap(const std::string& name);			/* Constructor by name */
		ScavTrap(const ScavTrap& other);			/* Copy Constructor */
		ScavTrap &operator=(const ScavTrap& other);	/* Copy assignment Constructor */
		~ScavTrap();								/* Destructor */

		void	guardGate(void);
		void	attack(const std::string& target);
};
