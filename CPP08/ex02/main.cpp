/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:26:47 by janhan            #+#    #+#             */
/*   Updated: 2024/09/05 16:38:21 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	std::cout << "MutantStacl< int >" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "mstack top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "mstack size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "MutantStacl< int, std::deque<int> >" << std::endl;
	{
		MutantStack<int, std::deque<int> > mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "mstack top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "mstack size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);

		MutantStack<int, std::deque<int> >::iterator it = mstack.begin();
		MutantStack<int, std::deque<int> >::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::deque<int> > s(mstack);
	}

	std::cout << "MutantStacl< int, std::list<int> >" << std::endl;
	{
		MutantStack<int, std::list<int> > mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "mstack top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "mstack size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);

		MutantStack<int, std::list<int> >::iterator it = mstack.begin();
		MutantStack<int, std::list<int> >::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(mstack);
	}


}
