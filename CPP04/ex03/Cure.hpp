/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:24:29 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 08:27:26 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
					Cure(void);
					Cure(const Cure& other);
					~Cure(void);
		Cure&		operator=(const Cure& other);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};
