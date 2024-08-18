/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:42:35 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:46:31 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>


class	Brain
{
	public:
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
