/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:44:10 by janhan            #+#    #+#             */
/*   Updated: 2024/07/17 13:05:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	mBrain = new Brain();
	std::cout << "Cat default constructor " << mType << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	mBrain = new Brain(*other.mBrain);
	std::cout << "Cat copy constructor " << mType << std::endl;
}

Cat::Cat(const Brain& brain) : Animal("Cat")
{
	mBrain = new Brain(brain);
	std::cout << "Cat default(brain) constructor" << mType << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	mType = other.mType;
	*mBrain = *other.mBrain;
	std::cout << "Cat assigment operator " << mType << std::endl;
	return (*this);
}

Cat::~Cat(void)
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
