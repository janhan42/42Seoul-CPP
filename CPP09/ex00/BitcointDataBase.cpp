/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcointDataBase.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 06:19:49 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 09:19:01 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcointDataBase.hpp"
#include <limits>

/* OCCF */
BitcoinDataBase::BitcoinDataBase()
{}

BitcoinDataBase::BitcoinDataBase(const BitcoinDataBase& rhs)
: mDataBase(rhs.getDataBase())
{}

BitcoinDataBase& BitcoinDataBase::operator=(const BitcoinDataBase &rhs)
{
	if (this != &rhs)
		setDataBase(rhs.getDataBase());
	return (*this);
}

float	BitcoinDataBase::getExcangeRateByDate(const std::string &date)
{
	BitcoinDataBase::MapT::const_iterator it = getDataBase().find(date);
	if (it != getDataBase().end())
		return (it->second);
	it = getDataBase().lower_bound(date);
	if (it != getDataBase().begin())
		return ((--it)->second);
	throw BitcoinDataBase::NopreviousDateFoundException();
}

void	BitcoinDataBase::importDataBase(const std::string &databaseFilePath)
{
	mDataBase.clear();
	std::ifstream inputFile(databaseFilePath.c_str());
	if (inputFile.is_open() == false)
		throw BitcoinDataBase::InvalidDatabaseException();
	std::string line;
	if (std::getline(inputFile, line))
	{
		if (line != std::string("date,exchange_rate"))
			throw BitcoinDataBase::InvalidDatabaseException();
	}
	while (std::getline(inputFile, line))
	{
		std::list<std::string> dateRate = split(line, ',');
		if (dateRate.size() != 2)
			throw BitcoinDataBase::InvalidDatabaseException();
		std::string date = dateRate.front();
		std::string rate = dateRate.back();
		char* endPtr = NULL;
		double doublerate = std::strtod(rate.c_str(), &endPtr);
		if (isDateFormat(date) == false
		|| rate.length() == 0
		|| *endPtr != '\0'
		|| (-static_cast<double>(std::numeric_limits<float>::max()) <= doublerate
		&& doublerate <= static_cast<double>(std::numeric_limits<float>::max()) == false))
			throw BitcoinDataBase::InvalidDatabaseException();
		mDataBase.insert(std::make_pair(date, static_cast<float>(doublerate)));
	}
	if (inputFile.eof())
		inputFile.close();
	else
		throw BitcoinDataBase::InvalidDatabaseException();
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
