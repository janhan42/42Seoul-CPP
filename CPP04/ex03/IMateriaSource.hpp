/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 07:07:26 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 08:24:17 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
# include <string>

class AMateria;
class IMateriaSource
{
	public:
		virtual				~IMateriaSource(void) {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(const std::string& type) = 0;
};
