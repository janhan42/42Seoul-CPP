/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:33:14 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:59:56 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

/*

	For every exercise, you have to provide the most complete tests you can.
	Constructor and destructor of each class must display specific messages. Don't use the
	same message for all classes.

	Start by implementing a simple base class called Animal. It has one protected atrribute:
		- std::string type;

	Implement a Dog class that inherits from Animal.
	Implement a Cat class that inherits from Animal.

	These two derived classes must set their type field depending on their name. Then,
	the Dog's type will be initialized to "Dog", and the Cat's type will be initialized to "Cat".
	The type of the Animal class can be left empty or set to the value of your choice.

	Every animal must be able to use the member function:
	makeSound()
	It will print an appropriate sound (cats don't bark)

	To ensure you understood how it works, inplement a WrongCat class that inherits from a
	WrongAnimal class. If you replace the Animal and the Cat by the wrong ones in the code above,
	the WrongCat should output the WrongAnimal sound.

	Implement and turn in more tests than the ones given above.

 */

class Animal
{
	public:
		/* OCCF */
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& othre);
		virtual	~Animal();

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
	protected:
		std::string mType;
};

#endif
