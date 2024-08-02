/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:23 by janhan            #+#    #+#             */
/*   Updated: 2024/08/02 09:18:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	printValue(bool result)
{
	if (result == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "fasle" << std::endl;
}

int main( void )
{
	/* 내부에 있음 */	/* TRUE */
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 2.0f, 2.0f )));
	/* 외부에 있음 */	/* FALSE */
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( -1.0f, 2.0f )));
	/* 꼭짓점에 있음 */	/* FALSE */
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 10.0f, 0.0f )));
	/* 가장자리에 있음 */	/* FALSE */
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 9.8f, 0.0f )));
	/* 내부에 있음 */	/* TRUE */
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 9.8f, 0.1f )));
	/* 끝점에서 살짝 위로 외부에 있음 */ /* FALSE */
	printValue(bsp( Point( 0.0f, 0.0f ), Point( 10.0f, 0.0f ),
					Point( 0.0f, 10.0f ), Point( 10.0f, 0.1f )));
	return 0;
}
