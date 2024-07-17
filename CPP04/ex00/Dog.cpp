/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:24:43 by janhan            #+#    #+#             */
/*   Updated: 2024/07/17 10:50:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor " << mType << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	*this = other;
	std::cout << "Dog copy constructor " << mType << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	mType = other.mType;
	std::cout << "Dog assigment operator " << mType << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor " << mType << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog sound! Bark!" << std::endl;
}
