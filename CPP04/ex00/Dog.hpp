/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:20:50 by janhan            #+#    #+#             */
/*   Updated: 2024/08/12 10:32:55 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();									/* Constructor */
		Dog(const Dog& other);					/* Copy Constructor */
		Dog&	operator=(const Dog& othre);	/* Copy Assignement operator */
		~Dog();									/* Destructir */

		void makeSound(void) const;				/* member function */
};
