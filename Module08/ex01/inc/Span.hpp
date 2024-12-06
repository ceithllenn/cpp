#pragma once

#include "colors.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
			unsigned int		n;
			std::vector<int>	tab;

	public:
			Span();
			Span(unsigned int size);
			Span(const Span &copy);

			Span& operator=(const Span &src);

			~Span();

			void	addNumber(int number);
			int		shortestSpan();
			int		longestSpan();
			void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

			class ContainerIsFullException: public std::exception
			{
				virtual const char* what() const throw();
			};

			class NotEnoughNumberException: public std::exception
			{
				virtual const char* what() const throw();
			};
};