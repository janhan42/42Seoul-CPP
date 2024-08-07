/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:24:24 by janhan            #+#    #+#             */
/*   Updated: 2024/08/06 07:25:02 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap1("Good");
	ClapTrap	clap2("Bad");
	ClapTrap	clap3("Same");
	ClapTrap	clap4 = clap3;

	clap1.attack("monster 1");
	clap2.attack("monster 2");

	clap1.takeDamage(5);
	clap2.takeDamage(4);

	clap1.beRepaired(5);
	clap2.beRepaired(4);

	clap1.takeDamage(10);
	clap1.takeDamage(10);
	clap2.takeDamage(10);
	clap2.takeDamage(10);

	clap1.attack("NPC");
	clap2.attack("NPC");
}
