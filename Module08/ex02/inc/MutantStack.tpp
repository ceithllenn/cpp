#include "MutantStack.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * MutantStack destructor
 */
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << ORNG << "MutantStack destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 *MutantStack default constructor
 */
template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << ORNG << "MutantStack default constructor called" << RST << std::endl;
}

/*
 * MutantStack copy constructor
 */
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
	std::cout << ORNG << "MutantStack copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * MutantStack assignation operator overload
 */
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &src)
{
	std::cout << ORNG << "MutantStack assignation operator overload" << RST << std::endl;
	if (*this != src)
	{
		this->c = src.c;
	}
	return (*this);
}

/**************************************************************************/
/*								ITERATORS		   						  */
/**************************************************************************/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}
