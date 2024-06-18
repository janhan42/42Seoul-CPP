/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:24:09 by janhan            #+#    #+#             */
/*   Updated: 2024/06/19 07:26:27 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	harl;

	std::cout << "\n" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\n" << std::endl;
	harl.complain("INFO");
	std::cout << "\n" << std::endl;
	harl.complain("WARNING");
	std::cout << "\n" << std::endl;
	harl.complain("ERROR");
	std::cout << "\n" << std::endl;

	return (0);
}
