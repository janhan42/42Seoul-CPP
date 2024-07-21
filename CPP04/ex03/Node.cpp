/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:49:00 by janhan            #+#    #+#             */
/*   Updated: 2024/07/21 12:03:10 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

Node::Node(void)
{
	setContent(0);
	setNextNode(0);
}

Node::Node(const Node& other)
{
	setContent(other.getContent());
	setNextNode(other.getNextNode());
}

Node::Node(void* content)
{
	setContent(content);
	setNextNode(0);
}

Node::~Node(void)
{

}

Node&	Node::operator=(const Node& other)
{
	mContent = other.getContent();
	mNextNode = other.getNextNode();

	return (*this);
}

void*	Node::getContent(void) const
{
	return (mContent);
}

void	Node::setContent(void* content)
{
	mContent = content;
}

Node*	Node::getNextNode(void) const
{
	return mNextNode;
}

void	Node::setNextNode(Node* nextNode)
{
	mNextNode = nextNode;
}
