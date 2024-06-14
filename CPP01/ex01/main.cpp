/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:21:56 by janhan            #+#    #+#             */
/*   Updated: 2024/06/14 19:22:41 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*arr = zombieHorde(11, "janhan");

	for (int i = 0; i < 11; i++)
		arr[i].announce();
	delete [] arr;
	return (0);
}
