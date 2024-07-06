/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:43:08 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 09:48:10 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap &operator=(const ScavTrap& other);
		~ScavTrap(void);

		void	guardGate(void);
};
