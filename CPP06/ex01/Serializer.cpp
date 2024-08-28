/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:22:44 by janhan            #+#    #+#             */
/*   Updated: 2024/08/29 00:25:12 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <atomic>
#include <cstdint>
#include <sys/_types/_uintptr_t.h>


/* Public */
std::uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(std::uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& rhs)
{
	(void)rhs;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
	(void)rhs;
	return (*this);
}

Serializer::~Serializer()
{
}
