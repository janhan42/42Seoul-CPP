/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:27:51 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:01:19 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
: AMateria("cure")
{
}

Cure::Cure(const Cure& other)
: AMateria(other)
{
}

Cure::~Cure()
{
}

Cure&	Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		mType = other.mType;
	}
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "s wounds *" << std::endl;
}
