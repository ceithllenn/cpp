#include "Span.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Span destructor
 */
Span::~Span()
{
	std::cout << OLIV << "Span destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Span default constructor
 */
Span::Span(): n(0)
{
	std::cout << "Span default constructor called" << RST << std::endl;
}

/*
 * Span constructor
 */
Span::Span(unsigned int size): n(size)
{
	std::cout << OLIV << "A Span of size " << n << " was created" << RST << std::endl;
}

/*
 * Span copy constructor
 */
Span::Span(const Span &copy)
{
	std::cout << OLIV << "Span copy constructor was called" << RST << std::endl;
	*this = copy;
}

/*
 * Span assignation operator overload
 */
Span& Span::operator=(const Span &src)
{
	std::cout << OLIV << "Span assignation operator called" << RST << std::endl;
	if (this == &src)
		return (*this);
	this->n = src.n;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Adds one number at the end of the tab
 */
void Span::addNumber(int number)
{
	if (tab.size() >= n)
		throw ContainerIsFullException();
	tab.push_back(number);
}

/*
 * Adds a range of number into the tab
 */
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (tab.size() + std::distance(begin, end) > n)
		throw ContainerIsFullException();
	tab.insert(tab.end(), begin, end);
}

/*
 * calculates the shortest span between two numbers in the tab
 */
int Span::shortestSpan(void)
{
	std::vector<int>	tmp = tab;
	int					min;

	if (tab.size() <= 1)
		throw NotEnoughNumberException();
	std::sort(tmp.begin(), tmp.end());
	min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if ((tmp[i] - tmp[i - 1]) < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

/*
 * calculates the longest span between two numbers in the tab
 */
int Span::longestSpan(void)
{
	std::vector<int>	tmp = tab;

	if (tab.size() <= 1)
		throw NotEnoughNumberException();
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

/**************************************************************************/
/*								EXCEPTIONS					   			  */
/**************************************************************************/

/*
 * Container is full
 */
const char *Span::ContainerIsFullException::what(void) const throw()
{
	return ("Container is full");
}

/*
 * Not enough number
 */
const char *Span::NotEnoughNumberException::what(void) const throw()
{
	return ("Not enough number");
}
