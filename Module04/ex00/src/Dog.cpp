#include "Dog.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Dog destructor
 */
Dog::~Dog()
{
	std::cout << BLUE << "Dog destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Dog default constructor
 */
Dog::Dog(): Animal("Dog")
{
	std::cout << BLUE << "Dog default constructor called" << RST << std::endl;
}

/*
 * Dog copy constructor
 */
Dog::Dog(Dog const &copy): Animal(copy)
{
	std::cout << BLUE << "Dog copy constructor called" << RST << std::endl;
}

/*
 * Dog assignation operator overload
 */
Dog& Dog::operator=(Dog const &src)
{
	std::cout << BLUE << "Dog assignation operator called" << RST << std::endl;
	this->type = src.type;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes a dog sound
 */
void Dog::makeSound(void) const
{
	std::cout << "WOOOOF WOOOF" << std::endl;
}
