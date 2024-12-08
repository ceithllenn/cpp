#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << REDD << "Usage: ./btc input.txt" << RST << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange	exchange;

		exchange.createDB("data.csv");
		exchange.processInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << REDD << e.what() << RST << std::endl;
		return (1);
	}
	return (0);
}
