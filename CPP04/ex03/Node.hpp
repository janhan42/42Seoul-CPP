/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:45:08 by janhan            #+#    #+#             */
/*   Updated: 2024/08/19 07:49:42 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef NODE_HPP
# define NODE_HPP
/* 아이템 착용 해제시 드랍할 노드 */

class Node
{
	public:
				Node();
				Node(const Node& other);
				Node(void* Content);
				~Node();
		Node&	operator=(const Node& other);

		void*	getContent(void) const;
		void	setContent(void* content);
		Node*	getNextNode(void) const;
		void	setNextNode(Node* nextNode);
	private:
		void*	mContent;
		Node*	mNextNode;
};

#endif
