/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:07:37 by janhan            #+#    #+#             */
/*   Updated: 2024/08/26 13:42:42 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	public:
		static void				convert(const std::string& literal);
		static void				PrintChar(void);
		static void				PrintInt(void);
		static void				PrintFloat(void);
		static void				PrintDouble(void);
	private:
		static std::string	mLiteral;
		static bool				isChar(void);
		static bool				isInt(void);
		static bool				isFloat(void);
		static bool				isDouble(void);

		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();
};

#endif
