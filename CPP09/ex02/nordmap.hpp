/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nordmap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:33:02 by janhan            #+#    #+#             */
/*   Updated: 2024/10/01 02:44:34 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef NORDMAP_HPP
# define NORDMAP_HPP

#include <deque>
#include <vector>
#include <utility>

template<typename Tkey, typename Tvalue, typename Tcontainer = std::vector<std::pair<Tkey, Tvalue> > >
class nordMap
{};


template<typename TKey>
class nordMap<TKey, std::deque<TKey>, std::deque<std::pair<TKey, std::deque<TKey> > > >
{
	public:
		nordMap(void) : mMap() {}
		std::deque<TKey>&	operator[](TKey key)
		{
			for (typename std::deque<std::pair<TKey, std::deque<TKey> > >::iterator it = mMap.begin(); it != mMap.end(); ++it)
			{
				if (it->first == key)
				{
					return it->second;
				}
			}
			mMap.push_back(std::pair<TKey, std::deque<TKey> >(key, std::deque<TKey>()));
			return mMap.back().second;
		}
		typename std::deque<TKey>::iterator begin(void)
		{
			return mMap.begin();
		}
		typename std::deque<TKey>::iterator end(void)
		{
			return mMap.end();
		}
	private:
		std::deque<std::pair<TKey, std::deque<TKey> > > mMap;
};

template<typename Tkey>
class nordMap<Tkey, std::vector<Tkey>, std::vector<std::pair<Tkey, std::vector<Tkey> > > >
{
	public:
		nordMap(void) : mMap() {}
		std::vector<Tkey>& operator[](Tkey key)
		{
			for (typename std::vector<std::pair<Tkey, std::vector<Tkey> > >::iterator it = mMap.begin(); it != mMap.end(); ++it)
			{
				if (it->first == key)
				{
					return it->second;
				}
			}
			mMap.push_back(std::pair<Tkey, std::vector<Tkey> >(key, std::vector<Tkey>()));
			return mMap.back().second;
		}
	private:
		std::vector<std::pair<Tkey, std::vector<Tkey> > > mMap;
};

#endif
