/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:29:45 by janhan            #+#    #+#             */
/*   Updated: 2024/07/17 11:38:20 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const	Animal*	meta	=	new Animal();
	const	Animal*	j		=	new Dog();
	const	Animal*	i		=	new Cat();

	std::cout << std::endl;

	std::cout << "Type is " << meta->getType() << std::endl;
	std::cout << "Type is " << i->getType() << std::endl;
	std::cout << "Type is " << j->getType() << std::endl;

	std::cout << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;

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

	return (0);
}
