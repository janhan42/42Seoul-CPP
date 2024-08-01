/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:22:53 by janhan            #+#    #+#             */
/*   Updated: 2024/08/01 11:43:49 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack("stack");
	Zombie	*heap = newZombie("heap");

	stack.announce();
	heap->announce();

	delete heap;
	{
		std::cout << std::endl
			<< "==============stack2 start==============" << std::endl;
		Zombie stack2("stack2");
		stack2.announce();
	std::cout << "==============stack2 end==============" << std::endl;
	}
	std::cout << "======================================" << std::endl;
	randomChump("stack_random");

	std::cout << "________________________\n";
	return (0);
}
