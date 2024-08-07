/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:21:13 by janhan            #+#    #+#             */
/*   Updated: 2024/08/07 07:40:56 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

/*

	Making ClapTraps is probably starting to get on your nerves.

	Now, Implement a FragTrap class that inherits from ClapTrap. It is very similar to
	ScavTrap. However, its construction and destruction messages must be different.
	Proper construction/destruction chaining must be shown in your tests.

	When a FragTrap is created, the program strats by building a ClapTrap.
	Destruction is in reverse order.

	Same things for the attributes, but with different values this time:
		- Name, which is passed as parameter to a cow
		- Attcak damage (30)

	FragTrap has a special capacity too:
		void highFivesGuys(void);

	This member function display a positive high fives request on the standard output.
	Again, add more tests your program.

 */

class FragTrap : public ClapTrap
{
	public:
		FragTrap();									/* Constructor */
		FragTrap(const std::string& name);			/* Constructor by name */
		FragTrap(const FragTrap& other);			/* Copy Constructor */
		FragTrap& operator=(const FragTrap& other);	/* Copy assignment Constructor */
		~FragTrap();								/* Destructor */

		void	highFivesGuys(void);				/* FragTrap function */
};
