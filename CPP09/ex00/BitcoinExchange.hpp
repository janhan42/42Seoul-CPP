/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:07:05 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 09:12:12 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHAGNE_HPP

#include <list>
#include <exception>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>

#include "split.hpp"
#include "isDateFormat.hpp"
#include "BitcointDataBase.hpp"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void		importDataBase(const std::string& dataBaseFilePath);
		void		exchange(const std::string& inputFIlePath);

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class EmptyDataBaseException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
	private:
		BitcoinDataBase mDatabase;
		std::list<std::string> mExchageResult;

		void	resetPreviousDate(std::string& date);
};

#endif
