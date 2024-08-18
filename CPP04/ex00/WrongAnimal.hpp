/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:49:17 by janhan            #+#    #+#             */
/*   Updated: 2024/08/18 13:01:51 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();											/* Constructor */
		WrongAnimal(std::string type);							/* Constructor by type */
		WrongAnimal(const WrongAnimal& other);					/* Copy Constructor */
		WrongAnimal&	operator=(const WrongAnimal& other);	/* Copy Assignment operator */
			~WrongAnimal();									/* Destructor */

		void	makeSound(void) const;							/* non virtual makeSound function */
		std::string	getType(void) const;						/* subject getType function */

	protected:
		std::string	mType;
};
