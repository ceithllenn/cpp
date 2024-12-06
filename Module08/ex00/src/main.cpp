#include "easyfind.hpp"
#include "colors.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << YLLW << "Test vector container"<< RST << std::endl;
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	try
	{
		std::cout << *easyfind(v, 5) << std::endl;
		std::cout << *easyfind(v, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << REDD << e.what() << std::endl;
	}


	std::cout << std::endl << YLLW << "Test list container" << RST << std::endl;
	std::list<int> l;

	for (int i = 0; i < 20; i++)
	{
		l.push_back(i);
	}
	try
	{
		std::cout << *easyfind(l, 0) << std::endl;
		std::cout << *easyfind(l, 1000) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << REDD << e.what() << std::endl;
	}


	std::cout << std::endl << YLLW << "Test deque container\n"<< RST << std::endl;
	std::deque<int> d;

	for (int i = 0; i < 350; i++)
	{
		d.push_back(i);
	}

	try
	{
		std::cout << *easyfind(d, 349) << std::endl;
		std::cout << *easyfind(d, 560) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << REDD << e.what() << RST << std::endl;
	}
	
	return (0);
}