#include "Cat.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Cat destructor
 */
Cat::~Cat()
{
	std::cout << GRNN << "Cat destructor called" << RST << std::endl;
	delete this->brain;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Cat default constructor
 */
Cat::Cat(): Animal("Cat"), brain(new Brain())
{
	std::cout << GRNN << "Cat default constructor called" << RST << std::endl;
}

/*
 * Cat copy constructor
 */
Cat::Cat(Cat const &copy): Animal(), brain(NULL)
{
	*this = copy;
	std::cout << GRNN << "Cat copy constructor called" << RST << std::endl;
}

/*
 * Cat assignation operator overload
 */
Cat& Cat::operator=(Cat const &src)
{
	std::cout << GRNN << "Cat assignation operator called" << RST << std::endl;
	this->type = src.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*src.brain);
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

Brain* Cat::getBrain(void) const
{
	return (this->brain);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes a cat sound
 */
void Cat::makeSound(void) const
{
	std::cout << "MEEEEEEOOOOWWWW" << std::endl;
}
