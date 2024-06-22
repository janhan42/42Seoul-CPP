/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:50:00 by janhan            #+#    #+#             */
/*   Updated: 2024/06/22 10:53:22 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{}

Point::Point(const Point& point) : _x(point.getX()), _y(point.getY())
{}

Point& Point::operator=(const Point &point)
{
	if (this != &point)
	{
		const_cast<Fixed&>(_x) = point.getX();
		const_cast<Fixed&>(_y) = point.getY();
	}
	return (*this);
}

Point::~Point(void)
{}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}
