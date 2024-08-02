/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:53:41 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 09:12:06 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	crossProduct(const Point& a, const Point& b, const Point& c)
{
	return Fixed(
		(b.getX().toFloat() - c.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()) -
		(b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat())
	);
}

bool isOnEdge(const Point& p, const Point& a, const Point& b)
{
	Fixed cross = crossProduct(p, a, b);
	if (cross != Fixed(0.0f))
		return false;

	// 점 p가 변 a-b의 범위 내에 있는지 확인
	return (p.getX().toFloat() >= std::min(a.getX().toFloat(), b.getX().toFloat()) &&
			p.getX().toFloat() <= std::max(a.getX().toFloat(), b.getX().toFloat()) &&
			p.getY().toFloat() >= std::min(a.getY().toFloat(), b.getY().toFloat()) &&
			p.getY().toFloat() <= std::max(a.getY().toFloat(), b.getY().toFloat()));
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed totalArea = crossProduct(a, b, c);

	if (totalArea == Fixed(0.0f))
		return false;

	Fixed aW = crossProduct(point, b, c) / totalArea;
	Fixed bW = crossProduct(point, c, a) / totalArea;
	Fixed cW = Fixed(1.0f) - aW - bW;

	if (point == a
	|| point == b
	|| point == c
	|| isOnEdge(point, a, b)
	|| isOnEdge(point, b, c)
	|| isOnEdge(point, c, a))
		return false;

	return (aW > Fixed(0.0f) && aW < Fixed(1.0f) &&
			bW > Fixed(0.0f) && bW < Fixed(1.0f) &&
			cW > Fixed(0.0f) && cW < Fixed(1.0f));
}
