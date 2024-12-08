#include "BitcoinExchange.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/**
 * @brief Destroy the BitcoinExchange object
 * 
 */
BitcoinExchange::~BitcoinExchange()
{
	std::cout << OLIV << "BitcoinExchange destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/**
 * @brief Construct a new BitcoinExchange object
 * 
 */
BitcoinExchange::BitcoinExchange()
{
	std::cout << OLIV << "BitcoinExchange default constructor called" << RST << std::endl;
}

/**
 * @brief BitcoinExchange copy constructor
 * 
 * @param copy 
 */
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << OLIV << "BitcoinExchange copy constructor called" << RST << std::endl;
	if (this != &copy)
		*this = copy;
}

/**
 * @brief BitcoinExchange assignation operator overload
 * 
 * @param src 
 */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	std::cout << OLIV << "BitcoinExchange assignation operator called" << RST << std::endl;
	if (this != &src)
		exchangeRate = src.exchangeRate;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/**
 * @brief Creates database from the data.csv file
 * 
 * @param filename 
 */
void BitcoinExchange::createDB(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line, date;
	double			rate;

	if (!file)
		throw CouldNotOpenFileException();

	if (std::getline(file, line))
	{
		if (line != "date,exchange_rate")
		{
			std::istringstream	ss(line);
			if (std::getline(ss, date, ',') && (ss >> rate))
				exchangeRate[date] = rate;
		}
	}

	while (getline(file, line))
	{
		std::stringstream	ss(line);
		if (getline(ss, date, ',') && (ss >> rate))
			exchangeRate[date] = rate;
	}
}

/**
 * @brief Gets the value of every valid exchange
 *			stipulated in the input file
 * 
 * @param filename input file
 */
void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line, dateS, valueS;
	double			value, rate;
	bool			begin = true;

	if (!file)
		throw CouldNotOpenFileException();

	while (getline(file, line))
	{
		trim(line);
		if (begin)
		{
			if (line == "date | value")
			{
				begin = false;
				continue ;
			}
		}
		begin = false;

		std::stringstream	ss(line);

		if (line[11] != '|' || line[10] != ' ' || line[12] != ' ')
		{
			line = line.empty() ? "empty" : line;
			std::cerr << REDD << "Error: bad input => " << line << RST << std::endl;
			continue ;
		}

		if (getline(ss, dateS, '|'))
		{
			if (!getline(ss, valueS))
			{
				std::cerr << REDD << "Error: bad input => " << line << RST << std::endl;
				continue ;
			}
			dateS.erase(dateS.find_last_not_of(" \n\r\t") + 1);
			valueS.erase(0, valueS.find_first_not_of(" \n\r\t"));

			if (!isValiDate(dateS))
			{
				std::cerr << REDD << "Error: bad input => " << dateS << RST << std::endl;
				continue ;
			}

			if (!isValidValue(valueS))
			{
				std::cerr << REDD << "Error: not a positive number." << RST << std::endl;
				continue ;
			}

			value = atof(valueS.c_str());
			if (value > 1000)
			{
				std::cerr << REDD << "Error: too large a number." << RST << std::endl;
				continue ;
			}

			rate = getExchangeRate(dateS);
			std::cout << dateS << " => " << value << " = " << value * rate << std::endl;
		}
		else
		{
			line = line.empty() ? "empty" : line;
			std::cerr << REDD << "Error: bad input => " << line << RST << std::endl;
		}
	}
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

/**
 * @brief Gets the rate of bitcoin at a specific date
 * 
 * @param date date to be looked for
 * @return rate or 0 if date cannot be found in database
 */
double BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = exchangeRate.lower_bound(date);

	if (it == exchangeRate.end() || it->first != date)
	{
		if (it == exchangeRate.begin())
			return (0);
		--it;
	}
	return (it->second);
}

/**************************************************************************/
/*							TOOLS METHODS					   			  */
/**************************************************************************/

/**
 * Char is not blank char
 */
bool isNotSpace(char c)
{
	return (!std::isspace(static_cast<unsigned char>(c)));
}

/**
 * Deletes blank characters at the end of a string
 */
std::string& ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), isNotSpace));
	return (s);
}

/**
 * deletes blank characters at the beginnning
 *  of a string
 */
std::string& rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), isNotSpace).base(), s.end());
	return (s);
}

/**
 * @brief Deletes blank characters at the beginning
 *			and at the end of a string
 */
std::string& trim(std::string &s)
{
	return (ltrim(rtrim(s)));
}

/**
 * @brief Checks if date is valid
 */
bool BitcoinExchange::isValiDate(const std::string &date) const
{
	int		year, month, day;
	bool	isLeap;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 4; i++)
	{
		if (!isdigit(date[i]))
			return (false);
	}

	for (int i = 5; i < 7; i++)
	{
		if (!isdigit(date[i]))
			return (false);
	}

	for (int i = 8; i < 10; i++)
	{
		if (!isdigit(date[i]))
			return (false);
	}

	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());

	if (month < 0 || month > 12 || day < 0 || day > 31)
		return (false);

	if (month == 2)
	{
		isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > 29 || (day == 29 && !isLeap))
			return (false);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
	}
	return (true);
}

/**
 * @brief Checks if a value is valid
 */
bool BitcoinExchange::isValidValue(const std::string &value) const
{
	char	*end;
	double	val = strtod(value.c_str(), &end);

	return (end != value.c_str() && *end == '\0' && val >= 0);
}

/**************************************************************************/
/*								EXCEPTIONS					   			  */
/**************************************************************************/

/**
 * @brief Error: could not open file
 *  
 */
const char *BitcoinExchange::CouldNotOpenFileException::what(void) const throw()
{
	return ("Error: could not open file");
}