/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:29:45 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 09:10:16 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void check(void)
{
	system("leaks Animal");
}

int	main(void)
{
	const	Animal*	meta	=	new Animal();
	const	Animal*	dog		=	new Dog();
	const	Animal*	cat		=	new Cat();

	std::cout << std::endl;

	std::cout << "Type is " << meta->getType() << std::endl;
	std::cout << "Type is " << cat->getType() << std::endl;
	std::cout << "Type is " << dog->getType() << std::endl;

	std::cout << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n------------------\n" << std::endl;

	const	WrongAnimal*	test = new WrongAnimal();
	const	WrongAnimal*	testCat = new WrongCat();

	std::cout << std::endl;

	std::cout << "Type is " << test->getType() << std::endl;
	std::cout << "Type is " << testCat->getType() << std::endl;

	std::cout << std::endl;

	test->makeSound();
	testCat->makeSound();

	std::cout << std::endl;

	delete test;
	delete testCat;

	atexit(check);
	return (0);
}
