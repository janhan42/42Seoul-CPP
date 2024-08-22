/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:43:38 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 09:08:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void check(void)
{
	system("leaks Magic");
}

int main(void)
{
	/* 스킬북에 스킬추가함 */
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	/* 새로운 캐릭터 생성 */
	ICharacter* me = new Character("me");
	AMateria* tmp;
	/* 스킬북에서 ice 장착 */
	tmp = src->createMateria("ice");
	me->equip(tmp);

	/* 스킬북에서 cure 장착 */
	tmp = src->createMateria("cure");
	me->equip(tmp);

	/* 새로운 캐릭터 생성 */
	ICharacter* bob = new Character("bob");

	/* bob에게 ice cure 사용 */
	me->use(0, *bob);
	me->use(1, *bob);

	/* bob에게 ice 장착 */
	bob->equip(src->createMateria("ice"));
	bob->use(0, *me);
	bob->unequip(0);
	bob->use(0, *me);

	delete bob;
	delete me;
	delete src;

	atexit(check);
	return 0;
}
