/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:32:56 by janhan            #+#    #+#             */
/*   Updated: 2024/08/29 13:34:46 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter&	operator=(const ScalarConverter& rhs);
		~ScalarConverter();
};

#endif
