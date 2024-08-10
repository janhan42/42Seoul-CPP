/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:26:01 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:48:53 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor " << mType << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
: WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copy constructor " << mType << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		mType = other.mType;
	}
	std::cout << "WrongCat copy assignment operator " << mType << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor " << mType << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound! Meow!" << std::endl;
}
