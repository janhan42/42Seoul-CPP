/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:42:35 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 08:00:14 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

/*

	Constructor and destructor of each class must display specific messages.

	Implement a Brain class. It cotains an array of 100 std::string called ides.
	This way. Dog and Cat will have private Brain* attribute.

	Upon constructor. Dog and Cat will create their Brain using new Brain();
	Upon destrcutor. Dog and Cat will delete their Brain.

	In your main function. create and fill an array of Animal object. Half of it will
	be Dog object and the other half will be Cat objects. At the end of your program
	execution. loop over this array and delete every Animal. You must delete directly
	dogs and cats an Animals. The appropriate destructor must be calld in the expected order.

	Don't forget to check for memory leaks.

	A copy of a Dog or a Cat mustn't be shallow. Thus, you have to test that your copies
	are deep copies!

 */
class	Brain
{
	public:
		/* OCCF */
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain();

		void					SetIdeaByIndex(const std::string& idea, int index);
		const	std::string&	GetIdeaByIndex(int index) const;

	private:
		std::string	mIdeas[100];
};

#endif
