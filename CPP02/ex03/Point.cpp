/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:50:00 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 08:59:39 by janhan           ###   ########.fr       */
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

Point::~Point()
{}

bool	Point::operator==(const Point& other) const
{
	if (mX == other.mX && mY == other.mY)
		return (true);
	else
		return (false);
}

Fixed	Point::getX(void) const
{
	return (mX);
}

Fixed	Point::getY(void) const
{
	return (mY);
}
