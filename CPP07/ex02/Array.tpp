/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:57:44 by janhan            #+#    #+#             */
/*   Updated: 2024/09/23 13:36:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <exception>
#include "Array.hpp"

/*
	매개 변수 없는 빈 생성자의 경우 mLength를 0로 지정 mArray를 new T[mLength]
로 생성 */
template <typename T>
Array<T>::Array()
: mLength(0)
, mArray(new T[mLength])
{}

/*

 */
template <typename T>
Array<T>::Array(const unsigned int n)
: mLength(n)
, mArray(new T[mLength])
{}

template <typename T>
Array<T>::Array(const Array& rhs)
: mLength(rhs.mLength)
, mArray(new T[mLength])
{
	for (unsigned int i = 0; i < mLength; ++i)
	{
		mArray[i] = rhs.mArray[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		delete [] mArray;
		mLength = rhs.mLength;
		mArray = new T[mLength];
		for (unsigned int i = 0; i < mLength; ++i)
		{
			mArray[i] = rhs.mArray[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](const unsigned int i) const
{
	if (i >= mLength)
		throw std::exception();
	return mArray[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] mArray;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return mLength;
}

#endif
