/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:24:09 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 11:56:52 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "usage: ./harlFilter <level>" << std::endl;
		return (1);
	}

	harl.complain(av[1]);
	return (0);
}
