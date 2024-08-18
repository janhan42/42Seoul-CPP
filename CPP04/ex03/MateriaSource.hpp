/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:56:48 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:07:39 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource();

		void			learnMateria(AMateria*);
		AMateria*		createMateria(const std::string& type);
		AMateria*		getMateriaByIndex(int index) const;
		void			setMateriaByIndex(AMateria* materia, int index);
	private:
		AMateria*	mMaterias[4];
};
