/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:20:50 by janhan            #+#    #+#             */
/*   Updated: 2024/07/17 12:51:03 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog(const Brain& brain);
		Dog&	operator=(const Dog& othre);
		~Dog(void);

		void					makeSound(void) const;
		void					SetIdeaByIndex(const std::string& idea, int index);
		const	std::string&	GetIdeaByIndex(int index) const;
	private:
		Brain*	mBrain;
};
