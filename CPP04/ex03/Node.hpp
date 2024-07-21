/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:45:08 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 12:45:41 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* 아이템 착용 해제시 드랍할 노드 */

class Node
{
	public:
				Node(void);
				Node(const Node& other);
				Node(void* Content);
				~Node(void);
		Node&	operator=(const Node& other);

		void*	getContent(void) const;
		void	setContent(void* content);
		Node*	getNextNode(void) const;
		void	setNextNode(Node* nextNode);
	private:
		void*	mContent;
		Node*	mNextNode;
};
