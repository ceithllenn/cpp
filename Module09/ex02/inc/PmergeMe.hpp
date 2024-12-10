#pragma once

#include "colors.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <algorithm>

class PmergeMe
{
	private:
			std::vector<int>	data_vector;
			std::list<int>		data_list;
			clock_t				start;
			clock_t				timeV;
			clock_t				timeL;

			std::list<int>		sortSequenceList(std::list<int> &l);
			std::vector<int>	sortSequenceVector(std::vector<int> &v);
			std::vector<int>	mergeVectors(std::vector<int> max, std::vector<int> v);
			std::list<int>		mergeLists(std::list<int> max, std::list<int> l);
			void				printSequence(bool flag) const;

	public:
			PmergeMe();
			PmergeMe(const PmergeMe &copy);
			PmergeMe& operator=(const PmergeMe &src);

			~PmergeMe();

			void	sortSequence();
			void	addNumber(int n);

			class DuplicateUnauthorizedException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};