/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:12:50 by janhan            #+#    #+#             */
/*   Updated: 2024/07/30 20:23:39 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

/*
	void	announce(void);
	output -> <name>: >: BraiiiiiiinnnzzzZ...
	Don't print the angle brackets (< and >).

	Then, inplement the two following functions:

	Zombie* newZombie(std::string name);
	It creates a zombie, name it,
	and return it so you can use it outside of the function scope.

	void randomChunmp(std::string name);
	It creates a zombie, name it, and the zombie announces itself.
*/

class Zombie
{
	public:
		Zombie();							/* Constructor */
		Zombie(const std::string& name);	/* Constructor by name */
		~Zombie();							/* Dstructor */
		void	announce(void) const;		/* Suject Functin */

	private:
		std::string mName;					/* member name */
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
