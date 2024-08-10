/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:07:42 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:18:05 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
: mType("<NULL>")
{
	std::cout << "Animal construrtor " << mType << std::endl;
}

Animal::Animal(std::string type)
: mType(type)
{
	std::cout << "Animal constructor " << mType << std::endl;
}

Animal::Animal(const Animal& other)
: mType(other.mType)
{
	std::cout << "Animal copy constructor " << mType << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		mType = other.mType;
	}
	std::cout << "Animal copy assignment operator " << mType << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor " << mType << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound!!!!!!!!!!!!" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->mType);
}
