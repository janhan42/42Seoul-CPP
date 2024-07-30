/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:46:39 by janhan            #+#    #+#             */
/*   Updated: 2024/07/30 19:55:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Fixed.hpp"

/*

	Let's start by creating the class Point in Orthodox Canonical Form
	that represents a 2D point:

		- Private members:
			- A Fixed const attribute x.
			- A Fixed const attribute y.
			- Anything else useful.

		- Public members:
			- A default constructor that initializes x and y to 0.
			- A constcutor that takes as parameters two constant floating-point numbers/
			It initializes x and y with those parameters.
			- A copy constructor.
			- A copy assignment operator overload.
			- A destructor.
			- Anything else useful.

		To conclude, inplement the following function in the appropriate file:
		bool	bsp( Point const a, Point const b, Point const c, Point const point );
			- a, b, c: The vertices of our beloved triangle.
			- point: Thte point to check.
			- Returns: Ture if the point is inside the triangle. False otherwise.
			Thus, if the point is a vertex or on edge, it will return False.

			Implment and turn in your own tests to ensure that your class  behaves as expected.

 */
class Point
{
	public:
		Point();									/* Default constructor */
		Point(const float x, const float y);		/* constructor takes as parameters two constant floating-point number */
		Point(const Fixed x, const Fixed y);		/* My constructor takes as parameters two constant Fixed */
		Point(const Point& point);					/* copy constructor */
		Point& operator=(const Point& point);		/* copy assignment operator */
		~Point();									/* destructor */

		Fixed	getX(void) const;					/* Getter */
		Fixed	getY(void) const;					/* Getter */
	private:
		const Fixed		mX;							/* const Fixed X */
		const Fixed		mY;							/* const Fixed Y */
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);
