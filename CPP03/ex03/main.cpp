/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:24:24 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:02:58 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
	DiamondTrap	diamondTrap("DiamondTrap");

	diamondTrap.attack("Target1");
	diamondTrap.takeDamage(20);
	diamondTrap.highFivesGuys();
	diamondTrap.beRepaired(20);
	diamondTrap.takeDamage(100);
	diamondTrap.attack("Clap");

	diamondTrap.whoAmI();
}
