/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:47:48 by janhan            #+#    #+#             */
/*   Updated: 2024/08/10 15:54:02 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor()
{
	setHead((Node*)0);
}

Floor::Floor(const Floor& other)
{
	clearList();
	setHead(copyList(other.getHead()));
}

Floor&	Floor::operator=(const Floor& other)
{
	clearList();
	setHead(copyList(other.getHead()));

	return (*this);
}

Floor::~Floor()
{
	clearList();
}

Node*	Floor::getHead(void) const
{
	return (mHead);
}

void	Floor::setHead(Node* head)
{
	mHead = head;
}

void	Floor::addNodeBack(AMateria* content)
{
	if (getHead() == (Node*)0)
		setHead(new Node(content));
	else
	{
		Node* temp = getHead();
		while(temp->getNextNode() != (Node*)0)
			temp = temp->getNextNode();
		temp->setNextNode(new Node(content));
	}
}

void	Floor::clearList(void)
{
	Node* temp = getHead();
	if (temp == (Node*)0)
		return;
	while (temp != (Node*)0)
	{
		delete (AMateria*) temp->getContent();
		temp->setContent((void*)0);
		Node* next = temp->getNextNode();
		delete temp;
		temp = next;
	}
	setHead((Node*)0);
}

Node*	Floor::copyList(Node* head)
{
	Node* temp = head;
	if (temp == (Node*)0)
		return (Node*)0;
	Node* res = new Node(temp->getContent());
	Node* curr = res;
	while (temp->getNextNode() != (Node*)0)
	{
		curr->setNextNode(new Node(temp->getNextNode()->getContent()));
		curr = curr->getNextNode();
		temp = temp->getNextNode();
	}
	return (res);
}
