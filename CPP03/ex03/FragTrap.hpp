/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:21:13 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:39:49 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();										/* Constructor */
		FragTrap(const std::string& name);				/* Constructor by name */
		FragTrap(const FragTrap& other);				/* Copy Constructor */
		FragTrap& operator=(const FragTrap& other);		/* Copy assignment Constructor */
		~FragTrap();									/* Destructor */

		void	highFivesGuys(void);
};
