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
			clock_t				v;
	//		clock_t				l;

			void	mergeVectors(std::vector<int> max);
	//		void	mergeLists(std::list<int> max);

	public:
			PmergeMe();
			PmergeMe(const PmergeMe &copy);
			PmergeMe& operator=(const PmergeMe &src);

			~PmergeMe();

			void	sortSequence();
			void	addNumber(int n);
			void	printSequence(bool flag) const;
			void	sortSequenceVector();
		//	void	sortSequenceList();

			class DuplicateUnauthorizedException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};