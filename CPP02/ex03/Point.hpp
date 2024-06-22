/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:46:39 by janhan            #+#    #+#             */
/*   Updated: 2024/06/22 10:49:28 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point& point);
		Point& operator=(const Point& point);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
	private:
		Fixed		_x;
		Fixed		_y;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif
