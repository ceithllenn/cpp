#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe	merge;

	if (argc < 2)
	{
		std::cerr << REDD << "Usage: ./PmergeMe n1 n2 n3 ..." << RST << std::endl;
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		if (!isdigit(*argv[i]))
		{
			std::cerr << REDD << "Error: all arguments must be positive intergers" << RST << std::endl;
			return (1);
		}

		long long tmp = atoll(argv[i]);
		if (tmp > __INT_MAX__)
		{
			std::cerr << REDD << "Error: maximum value for an interger is " << __INT_MAX__ << RST << std::endl;
			return (1);
		}

		try
		{
			merge.addNumber(atoi(argv[i]));
		}
		catch(const std::exception& e)
		{
			std::cerr << REDD << e.what() << RST << std::endl;
			return (1);
		}		
	}
	merge.sortSequence();
}