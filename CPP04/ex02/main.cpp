/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:29:45 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 09:06:28 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void check(void)
{
	system("leaks Animal");
}

int main()
{
	Animal* cat = new Cat();
	Animal* dog = new Dog();

	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;

	atexit(check);
	return 0;
}

