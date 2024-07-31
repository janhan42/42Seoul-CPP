/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:43:08 by janhan            #+#    #+#             */
/*   Updated: 2024/07/31 20:22:09 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

/*

	Because you can naver have enough ClapTraps, you will now create a derived robot.
	It will be narmed ScavTrap and will inherit hte constructor and destructor from Clap-Trap.
	However, its constructos, destructor and attack() will print different messages.
	After all, ClapTraps are aware of their individuality.

	Note that preper construction/destruction chaining must be shown in your tests.
	When a ScavTrap is created, the program starts by building a ClapTrap, Destruction is
	in reverse orderm Why?

	ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
	must initialize them to:

		- Name, which is passed as parameter to a constructor
		- Hit point (100), represent the health of the ClapTrap
		- Energy point (50)
		- Attcak damage (20)
	ScavTrap will also have its own special capacity:
		void	guardGate();
	This member function will display a message informing that ScavTrap is now in Gatekeeper mode.

		Don't forget to add more tests to your program.

 */

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();										/* Constructor */
		ScavTrap(const std::string& name);				/* Constructor by name*/
		ScavTrap(const ScavTrap& other);				/* Copy Constructor */
		ScavTrap &operator=(const ScavTrap& other);		/* Copy Assingment Cosntructor */
		~ScavTrap();									/* Destructor */

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif
