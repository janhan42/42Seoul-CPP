/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 10:28:47 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	printValue(bool result)
{
	if (result == true)
		std::cout << "RESULT : true" << std::endl << std::endl;
	else
		std::cout << "RESULT : fasle" << std::endl << std::endl;
}

int main( void )
{
	/* 내부에 있음 */	/* TRUE */
	std::cout << "내부에 있을 경우" << std::endl;
	std::cout << "A(0.0f, 0.0f), B(10.0f, 0.0f), C(0.0f, 10.0f), POINT(2.0f, 2.0f)" << std::endl;
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 2.0f, 2.0f )));

	/* 외부에 있음 */	/* FALSE */
	std::cout << "외부에 있을 경우" << std::endl;
	std::cout << "A(0.0f, 0.0f), B(10.0f, 0.0f), C(0.0f, 10.0f), POINT(-1.0f, 2.0f)" << std::endl;
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( -1.0f, 2.0f )));

	/* 꼭짓점에 있음 */	/* FALSE */
	std::cout << "꼭짓점에 있을 경우" << std::endl;
	std::cout << "A(0.0f, 0.0f), B(10.0f, 0.0f), C(0.0f, 10.0f), POINT(10.0f, 0.0f)" << std::endl;
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 10.0f, 0.0f )));

	/* 가장자리에 있음 */	/* FALSE */
	std::cout << "가장자리에 있을 경우" << std::endl;
	std::cout << "A(0.0f, 0.0f), B(10.0f, 0.0f), C(0.0f, 10.0f), POINT(9.8f, 0.0f)" << std::endl;
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 9.8f, 0.0f )));

	/* 내부에 있음 */	/* TRUE */
	std::cout << "내부에 있을 경우" << std::endl;
	std::cout << "A(0.0f, 0.0f), B(10.0f, 0.0f), C(0.0f, 10.0f), POINT(9.8f, 0.1f)" << std::endl;
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 9.8f, 0.1f )));

	/* 끝점에서 살짝 위로 외부에 있음 */ /* FALSE */
	std::cout << "끝점에서 살짝 외부에 있을 경우" << std::endl;
	std::cout << "A(0.0f, 0.0f), B(10.0f, 0.0f), C(0.0f, 10.0f), POINT(10.0f, 0.1f)" << std::endl;
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 10.0f, 0.1f )));

	/* 삼각형이 아닐경우 */ /* FALSE */
	std::cout << "삼각형이 아닐경우" << std::endl;
	std::cout << "A(0.0f, 0.0f), B(0.0f, 0.0f), C(0.0f, 0.0f), POINT(10.0f, 0.1f)" << std::endl;
	printValue(bsp( Point( 10.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 10.0f, 0.0f ), Point( 10.0f, 0.1f )));
	return 0;
}
