/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:12:50 by janhan            #+#    #+#             */
/*   Updated: 2024/07/04 17:28:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void ) const;
	private:
		std::string mName;

};

Zombie	*newZombie( std::string name );
void	randomChump(std::string name );

#endif
