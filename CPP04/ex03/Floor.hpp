/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:44:04 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:51:49 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"
# include "Node.hpp"

class Floor
{
	public:
		/* OCCF */
		Floor();
		Floor(const Floor& ohter);
		Floor&	operator=(const Floor& other);
		~Floor();

		Node*	getHead(void) const;
		void	setHead(Node* head);
		void	addNodeBack(AMateria* content);
		void	clearList(void);
		Node*	copyList(Node* head);
	private:
		Node*	mHead;
};

#endif
