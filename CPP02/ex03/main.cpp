/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 08:46:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	if ( bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 2.0f, 2.0f ) ) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "fasle" << std::endl;
	Point test;
	Point test2(0.5f, 0.5f);
	test =  test2;
	std::cout << test.getX() << test.getY() << std::endl;
	return 0;
}
