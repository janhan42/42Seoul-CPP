/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:07:42 by janhan            #+#    #+#             */
/*   Updated: 2024/07/09 22:11:20 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
: _type("<NULL>")
{
	std::cout << "Animal construrtor " << _type << std::endl;
}

Animal::Animal(std::string type)
: _type(type)
{
	std::cout << "Animal constructor " << _type << std::endl;
}

Animal::Animal(const Animal& other)
{
	_type = other._type;
	std::cout << "Animal copy constructor " << _type << std::endl;
}

Animal& Animal::operator=(const Animal &othre)
{
	_type = othre._type;
	std::cout << "Animal copy assignment operator " << _type << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor " << _type << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound!!!!!!!!!!!!" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}
