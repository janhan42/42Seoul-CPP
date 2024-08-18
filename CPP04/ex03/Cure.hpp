/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:24:29 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:04:22 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		/* OCCF */
		Cure();
		Cure(const Cure& other);
		Cure&		operator=(const Cure& other);
		~Cure();

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};
