/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:34:10 by janhan            #+#    #+#             */
/*   Updated: 2024/07/17 12:40:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constrcutor" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain copy constructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		SetIdeaByIndex(other.GetIdeaByIndex(i), i);
	std::cout << "Brain copy assigment operator" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor" << std::endl;
}

void	Brain::SetIdeaByIndex(const std::string& idea, int index)
{
	if (0 <= index && index < 100)
		mIdeas[index] = idea;
}

const	std::string&	Brain::GetIdeaByIndex(int index) const
{
	static const std::string	empty;
	if (0 <= index && index < 100)
		return (mIdeas[index]);
	else
		return empty;
}
