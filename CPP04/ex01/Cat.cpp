/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:44:10 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 08:56:01 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << "Cat default constructor " << mType << std::endl;
	mBrain = new Brain();
}

Cat::Cat(const Cat& other)
: Animal(other)
{
	std::cout << "Cat copy constructor " << mType << std::endl;
	mBrain = new Brain(*other.mBrain);
}

Cat::Cat(const Brain& brain)
: Animal("Cat")
{
	std::cout << "Cat default(brain) constructor" << mType << std::endl;
	mBrain = new Brain(brain);
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		mType = other.mType;
		*mBrain = *other.mBrain;
	}
	std::cout << "Cat assigment operator " << mType << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete mBrain;
	std::cout << "Cat destructor " << mType << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat sound! Meow!" << std::endl;
}

void	Cat::SetIdeaByIndex(const std::string& idea, int index)
{
	mBrain->SetIdeaByIndex(idea, index);
}

const std::string&	Cat::GetIdeaByIndex(int index) const
{
	return (mBrain->GetIdeaByIndex(index));
}
