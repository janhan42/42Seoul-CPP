/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:16:48 by janhan            #+#    #+#             */
/*   Updated: 2024/09/30 23:17:42 by janhan           ###   ########.fr       */
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

/* Copy Constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
: mDatabase(rhs.mDatabase)
, mExchageResult(rhs.mExchageResult)
{}

/* Copy Assignmet Operator */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		mDatabase = rhs.mDatabase;
		mExchageResult = rhs.mExchageResult;
	}
	return (*this);
}

/* Destructor */
BitcoinExchange::~BitcoinExchange()
{}

/**
 * @brief
 * 멥버로 가지고 있는 데이터 베이스를 import 하는 함수
 * @param dataBaseFilePath .csv File
 */
void	BitcoinExchange::importDataBase(const std::string &dataBaseFilePath)
{
	mDatabase.importDataBase(dataBaseFilePath);
}

void	BitcoinExchange::exchange(const std::string &inputFIlePath)
{
	if (mDatabase.getDatabaseSize() == 0)
		throw BitcoinExchange::InvalidInputException();
	std::ifstream inputFile(inputFIlePath.c_str());
	/* Input File Open Check */
	if (inputFile.is_open() == false)
		throw BitcoinExchange::InvalidInputException();
	std::string line;
	/* First Line Valid Check */
	if (std::getline(inputFile, line))
	{
		if (line != std::string("date | value"))
			throw BitcoinExchange::InvalidInputException();
	}

	while (std::getline(inputFile, line))
	{
		/* Input File Valid Check */
		std::list<std::string> splited = split(line, ' ');
		if (line.length() < 14
		|| line[4] != '-'
		|| line[7] != '-'
		|| line[10] != ' '
		|| line[11] != '|'
		|| line[12] != ' '
		|| splited.size() != 3
		|| isDateFormat(splited.front()) == false)
		{
			mExchageResult.push_back(std::string("Error: bad input => ") + line);
			continue;
		}
		/* Separated date & Amount */
		std::string date = splited.front();
		std::string Amount = splited.back();

		/* Amount Valid Check */
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
		/*
		데이터베이스에서 inputFile의 date를 기반으로 Rate를 가져온뒤 doubleAmount * mDataBase.Rate) 를 std::stringstream에 담아준다
		이따 std::exception을 케치하게 되는데 없는날짜 일떄 가장 가까운 이전 날짜를 기반으로 계산하기 때문에
		 */
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
