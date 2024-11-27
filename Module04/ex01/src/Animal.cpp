#include "Animal.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Animal destructor
 */
Animal::~Animal()
{
	std::cout << ORNG << "Animal destructor was called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Animal default constructor
 */
Animal::Animal(): type("no type")
{
	std::cout << ORNG << "Animal default constructor called" << RST << std::endl;
}

/*
 * Animal type constructor
 */
Animal::Animal(std::string s): type(s)
{
	std::cout << ORNG << "Animal type constructor called" << RST << std::endl;
}

/*
 * Animal copy constructor
 */
Animal::Animal(const Animal &copy)
{
	std::cout << ORNG << "Animal copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * Animal assignation operator overload
 */
Animal& Animal::operator=(Animal const &src)
{
	std::cout << ORNG << "Animal assignation operator called" << RST << std::endl;
	this->type = src.type;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes a sound
 */
void Animal::makeSound(void) const
{
	std::cout << REDD << "Error: no type Animal makes no sound" << RST << std::endl;
}
