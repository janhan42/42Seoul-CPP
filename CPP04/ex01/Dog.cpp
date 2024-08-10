/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:24:43 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:44:01 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << "Dog default constructor " << mType << std::endl;
	mBrain = new Brain();
}

Dog::Dog(const Dog& other)
: Animal(other)
{
	std::cout << "Dog copy constructor " << mType << std::endl;
	mBrain = new Brain(*other.mBrain);
}

Dog::Dog(const Brain& brain)
: Animal("Dog")
{
	std::cout << "Dog default(brain) constructor" << mType << std::endl;
	mBrain = new Brain(brain);
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		mType = other.mType;
		*mBrain = *other.mBrain;
	}
	std::cout << "Dog assigment operator " << mType << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete mBrain;
	std::cout << "Dog destructor " << mType << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog sound! Bark!" << std::endl;
}

void	Dog::SetIdeaByIndex(const std::string& idea, int index)
{
	mBrain->SetIdeaByIndex(idea, index);
}

const std::string&	Dog::GetIdeaByIndex(int index) const
{
	return (mBrain->GetIdeaByIndex(index));
}
