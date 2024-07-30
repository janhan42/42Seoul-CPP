/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:12:18 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 16:47:34 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

/*

	Somtimes you don't want to pay attention to everything Harl says.
	Implement a system to filter what Harl says depnding on the log levels
	you want to listen to.

	Create a program that takes as parameter one of the four levels.
	It will display all messages from level and above. For example:

	$> ./harlFilter "WARNING"
	[ WARNING ]
	I think I deserve to have some extra bacon for free.
	I've been coming for years whereas you started working here since last month.
	[ ERROR ]
	This is unacceptable, I want to speak to the manager now.
	$> ./harlFilter "I am not sure how tired I am today..."
	[ Probably complaining about insignificant problems ]

	Although there are several ways to deal with Harl, one of the most effective
	is to SWITCH if off.

	Give the name harlFilter to your executable.

	You must use, and maybe discover, the switch statement in this exercise.

	i: You can pass this module without doing exercise 06.
 */

class Harl
{
	public:
		Harl();									/* Constructor */
		~Harl();								/* Destructor */
		void	complain(std::string level);	/* Suject Function */
	private:
		void	debug(void);					/* Suject Function */
		void	info(void);						/* Suject Function */
		void	warning(void);					/* Suject Function */
		void	error(void);					/* Suject Function */
};

#endif
