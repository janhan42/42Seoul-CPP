/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:16:48 by janhan            #+#    #+#             */
/*   Updated: 2024/09/09 08:52:39 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "isDateFormat.hpp"
#include <limits>

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
		throw BitcoinExchange::InvalidInputException();
	std::ifstream inputFile(inputFIlePath.c_str());
	if (inputFile.is_open() == false)
		throw BitcoinExchange::InvalidInputException();
	std::string line;
	if (std::getline(inputFile, line))
	{
		if (line != std::string("date | value"))
			throw BitcoinExchange::InvalidInputException();
	}
	while (std::getline(inputFile, line))
	{
		std::list<std::string> splited = split(line, ' ');
		/*
			2011-01-03 | 3
		 */
		if (line.length() < 14
		|| line[10] != ' '
		|| line[11] != '|'
		|| line[12] != ' '
		|| splited.size() != 3
		|| isDateFormat(splited.front()) == false)
		{
			mExchageResult.push_back(std::string("Error: bad input => ") + line);
			continue;
		}
		std::string date = splited.front();
		std::string Amount = splited.back();
		char* endPtr = NULL;
		double BitcoinAmountDouble = std::strtod(Amount.c_str(), &endPtr);
		if (*endPtr != '\0')
		{
			mExchageResult.push_back(std::string("Error: bad input => ") + line);
			continue;
		}
		if (static_cast<double>(std::numeric_limits<int>::max()) < BitcoinAmountDouble)
		{
			mExchageResult.push_back(std::string("Error: too large a number."));
			continue;
		}
		if (BitcoinAmountDouble < 0.0)
		{
			mExchageResult.push_back(std::string("Error: not a positive number."));
			continue;
		}
		std::stringstream sstream;
		try
		{
			sstream << (BitcoinAmountDouble * mDatabase.getExcangeRateByDate(date));
		}
		catch (const std::exception& e)
		{
			mExchageResult.push_back((std::string("Error: no data.")));
			continue;
		}
		mExchageResult.push_back(date + std::string(" => ") + Amount + std::string(" = ") + sstream.str());
	}
}

const std::list<std::string>& BitcoinExchange::getExchangeResult(void) const
{
	return mExchageResult;
}

const char*	BitcoinExchange::InvalidInputException::what() const throw()
{
	return "Invalid Input";
}

const char* BitcoinExchange::EmptyDataBaseException::what() const throw()
{
	return "Empty DataBase";
}
