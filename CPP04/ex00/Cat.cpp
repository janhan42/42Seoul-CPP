/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:44:10 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 09:42:20 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat()
: Animal("Cat")
{
	std::cout << "Cat default constructor " << mType << std::endl;
}

Cat::Cat(const Cat& other)
: Animal(other)
{
	*this = other;
	std::cout << "Cat copy constructor " << mType << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	mType = other.mType;
	std::cout << "Cat assigment operator " << mType << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor " << mType << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat sound! Meow!" << std::endl;
}
