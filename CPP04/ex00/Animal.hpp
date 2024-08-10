/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:33:14 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:13:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class Animal
{
	public:
		Animal();									/* Constructor */
		Animal(std::string type);					/* Constructor by type */
		Animal(const Animal& other);				/* Copy Constructor */
		Animal&	operator=(const Animal& othre);		/* Copy Assignment Constructor */
		virtual	~Animal();							/* Destructor */

		virtual void	makeSound(void) const;		/* Subject Function makeSound(void) */
		std::string		getType(void) const;		/* Subject Function getType(void) */
	protected:
		std::string mType;
};
