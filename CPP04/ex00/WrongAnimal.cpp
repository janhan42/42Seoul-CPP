/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:52:55 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:19:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: mType("<NULL>")
{
	std::cout << "WrongAnimal default constructor " << mType << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
: mType(type)
{
	std::cout << "WrongAnimal default constructor " << mType << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
: mType(other.mType)
{
	std::cout << "WrongAnimal copy constructor " << mType << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		mType = other.mType;
	}
	std::cout << "WrongAnimal copy assignment operator " << mType << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor " << mType << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Sound!!!!!!" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (mType);
}
