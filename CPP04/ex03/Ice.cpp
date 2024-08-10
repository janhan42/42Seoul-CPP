/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:20:19 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:53:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
: AMateria("Ice")
{

}

Ice::Ice(const Ice& other)
: AMateria(other)
{

}

Ice::~Ice()
{

}

Ice&	Ice::operator=(const Ice& other)
{
	mType = other.getType();
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
