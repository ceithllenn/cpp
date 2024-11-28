#include "Brain.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Brain destructor
 */
Brain::~Brain()
{
	std::cout << YLLW << "Brain destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Brain default constructor
 */
Brain::Brain()
{
	std::cout << YLLW << "Brain default constructor called" << RST << std::endl;
}

/*
 * Brain copy constructor
 */
Brain::Brain(Brain const &copy)
{
	std::cout << YLLW << "Brain copy constructor" << RST << std::endl;
	*this = copy;
}

/*
 * Brain assignation operator overload
 */
Brain& Brain::operator=(Brain const &src)
{
	std::cout << YLLW << "Brain assignation operator called" << RST << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

void Brain::setIdea(int index, const std::string idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
	else
		std::cerr << REDD << "Index invalid" << RST << std::endl;
}

std::string Brain::getIdea(int index)
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	else
		std::cerr << REDD << "Index invalid" << RST << std::endl;
	return (NULL);
}