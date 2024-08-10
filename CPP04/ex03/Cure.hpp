/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:24:29 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:54:07 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
					Cure();
					Cure(const Cure& other);
					~Cure();
		Cure&		operator=(const Cure& other);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};
