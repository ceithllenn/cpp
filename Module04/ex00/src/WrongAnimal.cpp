#include "WrongAnimal.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * WrongAnimal destructor
 */
WrongAnimal::~WrongAnimal()
{
	std::cout << BROW << "WrongAnimal destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * WrongAnimal default constructor
 */
WrongAnimal::WrongAnimal(): type("no type")
{
	std::cout << BROW << "WrongAnimal default constructor called" << RST << std::endl;
}

/*
 * WrongAnimal type constructor
 */
WrongAnimal::WrongAnimal(std::string s): type(s)
{
	std::cout << BROW << "WrongAnimal type constructor called" << RST << std::endl;
}

/*
 * WrongAnimal copy constructor
 */
WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << BROW << "WrongAnimal copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * WrongAnimal assignation operator overload
 */
WrongAnimal& WrongAnimal::operator=(WrongAnimal const &src)
{
	std::cout << BROW << "WrongAnimal assignation operator called" << RST << std::endl;
	this->type = src.type;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes a sound
 */
void WrongAnimal::makeSound(void) const
{
	std::cout << REDD << "Error: even a WrongAnimal with no type makes no sound" << RST << std::endl;
}

