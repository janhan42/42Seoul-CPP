/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:33:14 by janhan            #+#    #+#             */
/*   Updated: 2024/07/09 22:07:19 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& othre);
		virtual	~Animal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
	protected:
		std::string _type;
};
