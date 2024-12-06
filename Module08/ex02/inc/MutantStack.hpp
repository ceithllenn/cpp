#pragma once

#include "colors.hpp"
#include <stack>
#include <iostream>

template <typename T>
class MutantStack: public std::stack <T>
{
	public:
			MutantStack();
			MutantStack(const MutantStack &copy);
			MutantStack& operator=(const MutantStack &src);

			~MutantStack();
			
		typedef typename std::stack<T>::container_type under_ctr;
		typedef typename under_ctr::iterator iterator;
		typedef typename under_ctr::const_iterator const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"