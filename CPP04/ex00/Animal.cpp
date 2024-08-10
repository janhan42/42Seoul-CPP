/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:07:42 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 16:02:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Constructor */
Animal::Animal()
: mType("<NULL>")
{
	std::cout << "Animal construrtor " << mType << std::endl;
}

/* Constructor by type */
Animal::Animal(std::string type)
: mType(type)
{
	std::cout << "Animal constructor " << mType << std::endl;
}

/* Copy Constructor */
Animal::Animal(const Animal& other)
: mType(other.mType)
{
	std::cout << "Animal copy constructor " << mType << std::endl;
}

/* Copy Assignment Constructor */
Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		mType = other.mType;
	}
	std::cout << "Animal copy assignment operator " << mType << std::endl;
	return (*this);
}

/* Destructor */
Animal::~Animal()
{
	std::cout << "Animal destructor " << mType << std::endl;
}

/* Member Function- */
void	Animal::makeSound(void) const
{
	std::cout << "Animal sound!!!!!!!!!!!!" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->mType);
}
