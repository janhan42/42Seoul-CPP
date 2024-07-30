/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:14:12 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 18:10:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl created." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl Destroyed." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-"
		<< " ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout
		<<  "I cannot believe adding extra bacon costs more money."
		<<  " You didn’t put enough bacon in my burger!"
		<<  " If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout
		<< "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming for years whereas"
		<< " you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	i = 0;
	for (; i < 4; i++)
		if (level == levels[i])
			break ;
	switch (i)
	{
		case 0:
		{
			this->debug();
			__attribute__((fallthrough));	// C와 C++에서 switch 문을 사용할때
		}									// break를 넣지 않으면 다음 case로 이동하게 되는데
		case 1:								// 이를 fallthrough라고하고 컴파일러 경고 메세지를 출력하지 않게 하고
		{									// 의도적으로 명시 하기 위해서 __atrribute__((fallthorugh)) 를 사용한다.
			this->info();
			__attribute__((fallthrough));
		}
		case 2:
		{
			this->warning();
			__attribute__((fallthrough));
		}
		case 3:
		{
			this->error();
			break ;
		}
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
