/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcointDataBase.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 06:05:51 by janhan            #+#    #+#             */
/*   Updated: 2024/09/08 09:18:56 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINDATABASE_HPP
# define BITCOINTDATABASE_HPP

#include <map>
#include <exception>
#include <fstream>
#include <limits>
#include <string>
#include <cstdlib>
#include <cstddef>
#include <list>

#include "split.hpp"
#include "isDateFormat.hpp"

class BitcoinDataBase
{
	public:
		/* OCCF */
		BitcoinDataBase();
		BitcoinDataBase(const BitcoinDataBase& rhs);
		BitcoinDataBase& operator=(const BitcoinDataBase& rhs);
		~BitcoinDataBase();

		float			getExcangeRateByDate(const std::string& date);
		void			importDataBase(const std::string& databaseFilePath);
		size_t			getDatabaseSize(void) const;

		class InvalidDatabaseException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class NopreviousDateFoundException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
	private:
		typedef std::map<std::string, float, std::less<std::string>,
		std::allocator<std::pair<const std::string, float> > >
			MapT;

		BitcoinDataBase::MapT			mDataBase;

		const BitcoinDataBase::MapT&	getDataBase(void) const;
		void							setDataBase(const BitcoinDataBase::MapT& database);
};

#endif
