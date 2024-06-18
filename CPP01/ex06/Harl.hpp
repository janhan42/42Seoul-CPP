/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:12:18 by janhan            #+#    #+#             */
/*   Updated: 2024/06/19 07:14:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
