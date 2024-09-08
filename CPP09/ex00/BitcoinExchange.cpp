/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:16:48 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 09:20:51 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* public */
BitcoinExchange::BitcoinExchange()
: mDatabase()
, mExchageResult()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
: mDatabase(rhs.mDatabase)
, mExchageResult(rhs.mExchageResult)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		mDatabase = rhs.mDatabase;
		mExchageResult = rhs.mExchageResult;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::importDataBase(const std::string &dataBaseFilePath)
{
	mDatabase.importDataBase(dataBaseFilePath);
}

void	BitcoinExchange::exchange(const std::string &inputFIlePath)
{
	if (mDatabase.getDatabaseSize() == 0)
		throw BitcoinExchange::InvalidInputException():
	std::ifstream inputFile(inputFIlePath.c_str());
}
