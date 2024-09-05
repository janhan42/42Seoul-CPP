/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:50:38 by janhan            #+#    #+#             */
/*   Updated: 2024/09/05 14:52:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template <typename Type, typename Container = std::deque<Type> >
class MutantStack : public std::stack<Type, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		iterator begin(void);
		iterator end(void);
		const_iterator begin(void) const;
		const_iterator end(void) const;
};

#include "MutantStack.tpp"

#endif
