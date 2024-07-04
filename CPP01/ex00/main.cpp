/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:22:53 by janhan            #+#    #+#             */
/*   Updated: 2024/07/04 17:29:51 by janhan           ###   ########.fr       */
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
		std::cout << "______________stack2 start_____________" << std::endl;
		Zombie stack2("stack2");
		stack2.announce();
	}
	std::cout << "______________stack2 end_____________" << std::endl;

	randomChump("stack_random");

	std::cout << "\n\n________________________\n";
	return (0);
}
