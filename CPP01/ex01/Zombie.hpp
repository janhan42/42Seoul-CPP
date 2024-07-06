/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:43:04 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 09:36:13 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void ) const;
		void	setName( std::string name );
	private:
		std::string mName;
};

Zombie	*zombieHorde( int N, std::string name );
