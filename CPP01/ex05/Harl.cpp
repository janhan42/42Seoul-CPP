/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:14:12 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 16:40:38 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl created." << std::endl;
}

Harl::~Harl(void)
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
	void	(Harl::*func[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			(this->*func[i])();
	/*
	levels에서 없는 커맨드가 들어올 경우
	아무것도 실행하지 않는 방향의 예외 처리 or 없는 컴플레인인지 메세지 출력
	*/
}
