/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:52:50 by janhan            #+#    #+#             */
/*   Updated: 2024/09/05 16:33:19 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename Type, typename Container>
typename Container::iterator MutantStack<Type, Container>::begin()
{
	return this->c.begin();
}

template <typename Type, typename Container>
typename Container::iterator MutantStack<Type, Container>::end()
{
	return this->c.end();
}

template <typename Type, typename Container>
typename Container::const_iterator MutantStack<Type, Container>::begin(void) const
{
	return this->c.begin();
}

template <typename Type, typename Container>
typename Container::const_iterator MutantStack<Type, Container>::end(void) const
{
	return this->c.end();
}
