/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:24:24 by janhan            #+#    #+#             */
/*   Updated: 2024/07/31 16:10:48 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	scav("scav");

	scav.attack("Clap");
	scav.takeDamage(20);
	scav.guardGate();
	scav.beRepaired(20);
	scav.takeDamage(100);
	scav.attack("Clap");
}
