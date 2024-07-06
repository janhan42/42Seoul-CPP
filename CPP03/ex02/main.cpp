/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:24:24 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 15:36:36 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	scav("scav");

	scav.attack("Clap");
	scav.takeDamege(20);
	scav.guardGate();
	scav.beRepaired(20);
	scav.takeDamege(100);
	scav.attack("Clap");
}
