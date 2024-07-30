/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:43:04 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 10:37:21 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

/*
	Implement the following function in the appropriate file:
	Zombie*	zombieHorde( int N, std::string name );

	It must allocate N Zombie objects in a single allocation.
	Then, it has to initialize the zombies, giving each one of
	them the name passed as parameter, The function returns a pointer
	to the first zombie.

	Implement your own tests to ensure your zombieHorde() function works as epected.
	Try to call announce() for each one of the zombies.

	Don't forget delete all the zombies and check for memory leaaks.
 */

class Zombie
{
	public:
		Zombie();								/* Constructor */
		Zombie(const std::string& name);		/* Constructor by Name*/
		~Zombie(); 								/* Destructor */
		void	announce( void ) const;			/* aonnounce function */
		void	setName( std::string name );	/* setter mName */
	private:
		std::string mName;						/* member Name */
};

Zombie	*zombieHorde( int N, std::string name );/* Subject Implement function */

#endif
