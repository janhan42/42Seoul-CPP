/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:53:41 by janhan            #+#    #+#             */
/*   Updated: 2024/06/22 11:08:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	crossProduct(const Point& a, const Point& b, const Point& c)
{
	return ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	totalArea(crossProduct(a, b, c));
	Fixed	aW = crossProduct(point, b, c) / totalArea;
	Fixed	bW = crossProduct(point, c, a) / totalArea;
	Fixed	cW = Fixed(1.0f) - aW - bW;

	if (totalArea == 0.0f)
		return false;
	else if (aW > 0.0f && aW < 1.0f
		&& bW > 0.0f && bW < 1.0f
		&& cW > 0.0f && cW < 1.0f )
		return true;
	else
		return false;
}
