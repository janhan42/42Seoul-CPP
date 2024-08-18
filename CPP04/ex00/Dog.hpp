/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:20:50 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:59:09 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		/* OCCF */
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& othre);
		~Dog();						/* override */

		void makeSound(void) const;	/* override */
};

#endif
