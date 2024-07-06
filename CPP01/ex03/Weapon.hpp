/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:47:37 by janhan            #+#    #+#             */
/*   Updated: 2024/07/06 07:04:17 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon(std::string name);
		~Weapon(void);

		void				setType(std::string type);
		const std::string&	getType() const;
	private:
		std::string mType;
};
