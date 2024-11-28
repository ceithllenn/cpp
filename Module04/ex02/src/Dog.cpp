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
	delete this->brain;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Dog default constructor
 */
Dog::Dog(): Animal("Dog"), brain(new Brain())
{
	std::cout << BLUE << "Dog default constructor called" << RST << std::endl;
}

/*
 * Dog copy constructor
 */
Dog::Dog(Dog const &copy): Animal(), brain(NULL)
{
	*this = copy;
	std::cout << BLUE << "Dog copy constructor called" << RST << std::endl;
}

/*
 * Dog assignation operator overload
 */
Dog& Dog::operator=(Dog const &src)
{
	std::cout << BLUE << "Dog assignation operator called" << RST << std::endl;
	this->type = src.type;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain(*src.brain);
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

Brain* Dog::getBrain(void) const
{
	return (this->brain);
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
