/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:24:09 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 16:40:54 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	harl;

	std::cout <<  std::endl;
	harl.complain("DEBUG");
	std::cout <<  std::endl;
	harl.complain("INFO");
	std::cout <<  std::endl;
	harl.complain("WARNING");
	std::cout <<  std::endl;
	harl.complain("ERROR");
	std::cout <<  std::endl;
	harl.complain("Worng");
	std::cout << std::endl;
	return (0);
}
