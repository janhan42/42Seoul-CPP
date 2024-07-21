/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:56:48 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 13:11:47 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	mMaterias[4];
	public:
						MateriaSource(void);
						MateriaSource(const MateriaSource& other);
						~MateriaSource(void);
		MateriaSource&	operator=(const MateriaSource& other);

		void			learnMateria(AMateria*);
		AMateria*		createMateria(const std::string& type);
		AMateria*		getMateriaByIndex(int index) const;
		void			setMateriaByIndex(AMateria* materia, int index);
};
