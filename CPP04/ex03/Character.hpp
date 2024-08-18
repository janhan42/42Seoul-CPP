/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:00:11 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:47:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Floor.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(const Character& ohter);
		Character(const std::string& name);
		Character&			operator=(const Character& ohter);
		~Character();

		const std::string&	getName(void) const;
		void				setName(const std::string& name);
		AMateria*			getInvenByIndex(int index) const;
		void				setInvenByIndex(AMateria*	item, int index);

		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
	private:
		std::string 		mName;
		AMateria*			mInventory[4];
		Floor				mFloor;
};

#endif
