/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:07:25 by jeekpark          #+#    #+#             */
/*   Updated: 2024/08/10 15:55:16 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
: mType("<NULL>")
{
}

AMateria::AMateria(const std::string& type)
: mType(type)
{
}

AMateria::AMateria(const AMateria& other)
: mType(other.mType)
{
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		mType = other.mType;
	return (*this);
}

/* member function */
const std::string&	AMateria::getType(void) const
{
	return (mType);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "This is abstract materia." << std::endl;
}
