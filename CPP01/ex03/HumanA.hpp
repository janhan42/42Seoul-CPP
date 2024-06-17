/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:51:39 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 22:53:18 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& _weapon);
		~HumanA( void );

		void	attack(void);
	private:
		std::string	_name;
		Weapon&		_Weapon;
};

#endif
