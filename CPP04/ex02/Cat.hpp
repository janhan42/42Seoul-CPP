/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:42:53 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:42:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat(const Brain& brain);
		Cat&	operator=(const Cat& other);
		~Cat();

		void					makeSound(void) const;
		void					SetIdeaByIndex(const std::string& idea, int index);
		const	std::string&	GetIdeaByIndex(int index) const;
	private:
		Brain*	mBrain;
};

#endif
