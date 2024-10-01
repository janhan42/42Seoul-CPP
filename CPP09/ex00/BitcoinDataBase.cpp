/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinDataBase.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 06:19:49 by janhan            #+#    #+#             */
/*   Updated: 2024/09/30 23:36:47 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinDataBase.hpp"
#include <limits>

/* OCCF */
BitcoinDataBase::BitcoinDataBase()
{}

/* Copy Constructor */
BitcoinDataBase::BitcoinDataBase(const BitcoinDataBase& rhs)
: mDataBase(rhs.getDataBase())
{}

/* Copy Assignment Operator */
BitcoinDataBase& BitcoinDataBase::operator=(const BitcoinDataBase &rhs)
{
	if (this != &rhs)
		setDataBase(rhs.getDataBase());
	return (*this);
}

/* Destructor */
BitcoinDataBase::~BitcoinDataBase()
{}

/**
 * @brief
 * .csv file을 std::map 형태로 import 하는 함수
 * @param databaseFilePath
 */
void	BitcoinDataBase::importDataBase(const std::string &databaseFilePath)
{
	mDataBase.clear();
	std::ifstream inputFile(databaseFilePath.c_str());
	/* File Open Faile Check */
	if (inputFile.is_open() == false)
		throw BitcoinDataBase::InvalidDatabaseException();
	std::string line;
	/* First Line Valid Check */
	if (std::getline(inputFile, line))
	{
		if (line != std::string("date,exchange_rate"))
			throw BitcoinDataBase::InvalidDatabaseException();
	}
	while (std::getline(inputFile, line))
	{
		std::list<std::string> dateRate = split(line, ',');
		/* 2015-05-02,230.97 Pair Check */
		if (dateRate.size() != 2)
			throw BitcoinDataBase::InvalidDatabaseException();
		/* Separate date rate */
		std::string date = dateRate.front();
		std::string rate = dateRate.back();

		/* Converte rate Value String to float */
		char* endPtr = NULL;
		double doublerate = std::strtod(rate.c_str(), &endPtr);
		if (isDateFormat(date) == false
		|| rate.length() == 0
		|| *endPtr != '\0'
		|| (-static_cast<double>(std::numeric_limits<float>::max()) <= doublerate
		&& doublerate <= static_cast<double>(std::numeric_limits<float>::max()) == false))
			throw BitcoinDataBase::InvalidDatabaseException();
		/* Make std::map pair date & float rate value */
		mDataBase.insert(std::make_pair(date, static_cast<float>(doublerate)));
	}
	/* File ifstream close check */
	if (inputFile.eof())
		inputFile.close();
	else
		throw BitcoinDataBase::InvalidDatabaseException();
}

/**
 * @brief
 * date 를 기반으로 DataBase에서 Value(float)를 찾아서 반환
 * @param date std::string
 * @return float
 */
float	BitcoinDataBase::getExcangeRateByDate(const std::string &date)
{
	BitcoinDataBase::MapT::const_iterator it = getDataBase().find(date);
	if (it != getDataBase().end())
		return (it->second);
	it = getDataBase().lower_bound(date);
	/* lower_bound는 date가 없다면 더 큰 key값을 찾아서 iterator를 반환 */
	if (it != getDataBase().begin())
		return ((--it)->second);
	/* 위에서 리턴되지 않았다면 이전날짜가 없기때문에 Exception */
	throw BitcoinDataBase::NopreviousDateFoundException();
}


size_t	BitcoinDataBase::getDatabaseSize(void) const
{
	return getDataBase().size();
}

const char* BitcoinDataBase::InvalidDatabaseException::what(void) const throw()
{
	return "Invalid database";
}

const char* BitcoinDataBase::NopreviousDateFoundException::what(void) const throw()
{
	return "No previouse date found";
}

/* Private */
const BitcoinDataBase::MapT& BitcoinDataBase::getDataBase(void) const
{
	return mDataBase;
}
void BitcoinDataBase::setDataBase(const BitcoinDataBase::MapT& database)
{
	mDataBase = database;
}
