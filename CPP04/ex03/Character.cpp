/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:51:53 by jeekpark          #+#    #+#             */
/*   Updated: 2024/08/10 15:54:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	setName("<null>");
	for (int i = 0; i < 4; ++i)
		setInvenByIndex(NULL, i);
	std::cout << "I AM " << getName() << "!" << std::endl;
}

Character::Character(const std::string& name)
{
	setName(name);
	for (int i = 0; i < 4; ++i)
		setInvenByIndex(NULL, i);
	std::cout << "I AM " << getName() << "!" << std::endl;
}

Character::Character(const Character& copy)
{
	setName(copy.getName());
	mFloor.clearList();
	mFloor.copyList(copy.mFloor.getHead());
	for (int i = 0; i < 4; ++i)
	{
		AMateria* temp = copy.getInvenByIndex(i);
		if (temp == NULL)
			setInvenByIndex(NULL, i);
		else
			setInvenByIndex(temp->clone(), i);
	}
	std::cout << "I AM " << getName() << "!" << std::endl;
}

Character::~Character()
{
	mFloor.clearList();
	for (int i = 0; i < 4; ++i)
	{
		delete getInvenByIndex(i);
		setInvenByIndex(NULL, i);
	}
}

Character&	Character::operator=(const Character& copy)
{
	setName(copy.mName);
	mFloor.clearList();
	mFloor.copyList(copy.mFloor.getHead());
	for (int i = 0; i < 4; ++i)
	{
		delete mInventory[i];
		AMateria* temp = copy.getInvenByIndex(i);
		if (temp == NULL)
			setInvenByIndex(NULL, i);
		else
			setInvenByIndex(temp->clone(), i);
	}
	return *this;
}

AMateria*	Character::getInvenByIndex(int index) const
{
	if (0 <= index && index < 4)
		return mInventory[index];
	else
		return NULL;
}

void	Character::setInvenByIndex(AMateria* Inven, int index)
{
	if (0 <= index && index < 4)
		mInventory[index] = Inven;
}

const std::string&	Character::getName(void) const
{
	return mName;
}

void	Character::setName(const std::string& name)
{
	mName = name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
		if (getInvenByIndex(i) == NULL)
		{
			setInvenByIndex(m, i);
			return ;
		}
}

void	Character::unequip(int idx)
{
	mFloor.addNodeBack(getInvenByIndex(idx));
	setInvenByIndex(NULL, idx);
}

void	Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx < 4)
	{
		AMateria*	temp = getInvenByIndex(idx);
		if (temp != NULL)
			getInvenByIndex(idx)->use(target);
	}
}
