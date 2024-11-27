#include "WrongCat.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * WrongCat destructor
 */
WrongCat::~WrongCat()
{
	std::cout << OLIV << "WrongCat destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * WrongCat default constructor
 */
WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << OLIV << "WrongCat default constructor called" << RST << std::endl;
}

/*
 * WrongCat copy constructor
 */
WrongCat::WrongCat(WrongCat const &copy): WrongAnimal(copy)
{
	std::cout << OLIV << "WrongCat copy constructor called" << RST << std::endl;
}

/*
 * WrongCat assignation operator overload
 */
WrongCat& WrongCat::operator=(WrongCat const &src)
{
	std::cout << OLIV << "WrongCat assignation operator called" << RST << std::endl;
	this->type = src.type;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes a sound
 */
void WrongCat::makeSound(void) const
{
	std::cout << "Woof Woof ?" << std::endl;
}
