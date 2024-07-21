/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:07:25 by jeekpark          #+#    #+#             */
/*   Updated: 2024/07/21 13:10:22 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	mType = "<null>";
}
AMateria::AMateria(const std::string& type)
{
	mType = type;
}

AMateria::AMateria(const AMateria& copy)
{
	mType = copy.mType;
}

AMateria::~AMateria(void)
{

}

AMateria&	AMateria::operator=(const AMateria& copy)
{
	mType = copy.mType;
	return *this;
}

/* member function */

const std::string&	AMateria::getType(void) const
{
	return mType;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "This is abstract materia." << std::endl;
}
