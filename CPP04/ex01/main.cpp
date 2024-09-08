/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:29:45 by janhan            #+#    #+#             */
/*   Updated: 2024/08/22 18:44:04 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // should not create a leak
	delete i;

	std::cout << "\n\n\n\n" << std::endl;

	Brain* brain = new Brain();
	brain->SetIdeaByIndex("hello", 0);

	Cat	cat = Cat(*brain);
	Dog dog = Dog(*brain);

	delete brain;

	std::cout << "\n\n\n" << cat.GetIdeaByIndex(0) << std::endl;
	std::cout << dog.GetIdeaByIndex(0) << "\n\n" << std::endl;

	return 0;
}

