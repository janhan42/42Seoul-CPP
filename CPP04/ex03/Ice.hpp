/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:18:19 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:53:40 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
					Ice();
					Ice(const Ice& other);
					~Ice();
		Ice&		operator=(const Ice& other);

		AMateria*	clone(void) const; // subject
		void		use(ICharacter& target);
};
