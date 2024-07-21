/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:42:35 by janhan            #+#    #+#             */
/*   Updated: 2024/07/17 11:57:33 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>


class	Brain
{
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain(void);

		void					SetIdeaByIndex(const std::string& idea, int index);
		const	std::string&	GetIdeaByIndex(int index) const;

	private:
		std::string	mIdeas[100];
};
