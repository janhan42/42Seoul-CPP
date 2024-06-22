/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:56:23 by janhan            #+#    #+#             */
/*   Updated: 2024/06/22 11:09:03 by janhan           ###   ########.fr       */
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

	return 0;
}
