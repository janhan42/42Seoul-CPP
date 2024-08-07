/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:44:04 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 13:03:27 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "Node.hpp"

class Floor
{
	public:
				Floor(void);
				Floor(const Floor& ohter);
				~Floor(void);
		Floor&	operator=(const Floor& other);

		Node*	getHead(void) const;
		void	setHead(Node* head);
		void	addNodeBack(AMateria* content);
		void	clearList(void);
		Node*	copyList(Node* head);
	private:
		Node*	mHead;
};
