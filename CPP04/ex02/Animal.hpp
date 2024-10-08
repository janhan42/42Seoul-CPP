/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:33:14 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:41:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& othre);
		virtual	~Animal();

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
	protected:
		std::string mType;
};

#endif
