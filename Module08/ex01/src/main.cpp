#include "Span.hpp"
#include <cstdlib>

int main()
{
	std::cout << YLLW << "Main subject test:" << RST << std::endl << std::endl;
	
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		sp.addNumber(12);
	}
	catch (std::exception &e)
	{
		std::cerr << REDD << e.what() << RST << std::endl;
	}
	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << YLLW << "\nTest large range of numbers" << RST << std::endl << std::endl;
	
	Span sp3 = Span(100000);
	std::vector<int> v2;
	std::srand(time(NULL));

	for (int i = 0; i < 100000; i++)
	{
		
		int random_int = rand() % 1000000000;
		v2.push_back(random_int);
	}
	try
	{
		sp3.addNumber(v2.begin(), v2.end());
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << REDD << e.what() << RST << std::endl;
	}
}
