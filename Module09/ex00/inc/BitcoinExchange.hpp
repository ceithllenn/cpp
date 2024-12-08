#pragma once

#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include "colors.hpp"

/**
 * @brief BitcoinExchange class
 * 
 */
class BitcoinExchange
{
	private:
			std::map<std::string, double> exchangeRate;
			bool	isValiDate(const std::string &date) const;
			bool	isValidValue(const std::string &value) const;

	public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange &copy);
			BitcoinExchange& operator=(const BitcoinExchange &src);

			~BitcoinExchange();

			void	createDB(const std::string &file);
			void	processInput(const std::string &file);

			double	getExchangeRate(const std::string &date) const;

			class CouldNotOpenFileException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};

std::string& trim(std::string &s);
