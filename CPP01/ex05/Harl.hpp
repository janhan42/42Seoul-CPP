/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:12:18 by janhan            #+#    #+#             */
/*   Updated: 2024/07/29 15:31:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>


/*
	Do You know Harl? We all do, do we? In case you don't, find below the
	kind of comments Harl makes. They are classified by levels:

	- 'DEBUG' level: Debug messages contain contextual information. They are mostly
	used for problem diafnosis.
	Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-
ketchup burger. I really do!"
	- 'INFO' level: These messages contain extensive information. They are helpful for
	tracing program execution in prodution evironment.
	Example: "I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!"

	- 'WARNING' level: Wraning messages incdicate a potential insue in the system.
	Howerve, it can be handled or ignored.
	Example: "I think I deserve to have some extra bacon for free. I’ve been coming for
years whereas you started working here since last month."

	- 'ERROR' level: These messages indicate an unrecoverable error has occurred.
	This is usually a critical issue that requires manual intervenion.
	Example: "This is unacceptable! I want to speak to the manager now."

	you are going to automate Harl. it won't be difficult since is always sthe same things.
	You have to create a Harl class with the following private memver functions:

	- void debug( void );
	- void info( void );
	- void warning(void);
	- void error( void );

	Harl also has a public member function that calls the four member functions above
	depending on the level passed as parameter:

	void	complain( std::string level );

	The goal of this exercise is to use **pointer to member functions**.
	This is not a suggetion. Harl has to complain whiout using a foreset of if / else if / else.
	It doesn't think twice!


 */

class Harl
{
	public:
		Harl();									/* Constructor */
		~Harl();								/* Destructor */
		void	complain(std::string level); 	/* Subject function */
	private:
		void	debug(void);					/* Subject function */
		void	info(void);						/* Subject function */
		void	warning(void);					/* Subject function */
		void	error(void);					/* Subject function */
};

#endif
