/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:29:45 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 12:26:56 by janhan           ###   ########.fr       */
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
	Animal*	Zoo[100];
	Brain*	brain = new Brain();
	brain->SetIdeaByIndex("Hello", 0);

	for (int i = 0; i < 100; i++)
	{
		std::cout << "Index [" << i << "]\n";
		if (i < 50)
			Zoo[i] = new Dog();
		else
			Zoo[i] = new Cat;
		std::cout << std::endl;
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << "Index [" << i << "]\n";
		delete Zoo[i];
		std::cout << std::endl;
	}
	return (0);
}

