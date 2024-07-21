/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:27:51 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 08:29:53 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void)
: AMateria("Cure")
{

}

Cure::Cure(const Cure& other)
: AMateria(other)
{

}

Cure::~Cure(void)
{

}

Cure&	Cure::operator=(const Cure& other)
{
	mType = other.getType();
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
