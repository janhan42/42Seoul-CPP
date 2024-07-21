/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 07:11:12 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 12:08:16 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string mType;
	public:
							AMateria(void);
							AMateria(const std::string& type); // subject
							AMateria(const AMateria& other);
		virtual				~AMateria(void);
		AMateria&			operator=(const AMateria& other);

		const std::string&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};
