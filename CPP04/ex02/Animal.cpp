/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:07:42 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 07:00:19 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
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
{
	mType = other.mType;
	std::cout << "Animal copy constructor " << mType << std::endl;
}

Animal& Animal::operator=(const Animal &othre)
{
	mType = othre.mType;
	std::cout << "Animal copy assignment operator " << mType << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor " << mType << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->mType);
}
