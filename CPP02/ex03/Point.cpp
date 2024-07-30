/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:50:00 by janhan            #+#    #+#             */
/*   Updated: 2024/07/30 20:22:24 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
: mX(0)
, mY(0)
{}

Point::Point(const float x, const float y)
: mX(x)
, mY(y)
{}

Point::Point(const Fixed x, const Fixed y)
: mX(x)
, mY(y)
{}

Point::Point(const Point& point)
: mX(point.getX())
, mY(point.getY())
{}

// Point -> pa=pb
// fixed -> fa -> value
// const 상수잖아 -> 변수를 한번 초기화하고나면 값을 못바꿔
// Point a = ab;
// a =b, a내부의 mx, my b mx, my
// Fixed const x -> x라는 인스턴스는 유지
// x.value <- int

/*
	C++ 내부 기본 세팅으로는 const 맴버 변수는 초기화 하지 않지만
	const_cast 를 사용해서 강제로 케스팅
*/
Point& Point::operator=(const Point &point)
{
	if (this != &point)
	{
		const_cast<Fixed&>(mX) = point.getX();
		const_cast<Fixed&>(mY) = point.getY();
	}
	return (*this);
}

Point::~Point()
{}

Fixed	Point::getX(void) const
{
	return (mX);
}

Fixed	Point::getY(void) const
{
	return (mY);
}
