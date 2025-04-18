#include "Ice.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Ice destructor
 */
Ice::~Ice()
{
	std::cout << BLUE << "Ice destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Ice default constructor
 */
Ice::Ice(): AMateria("ice")
{
	std::cout << BLUE << "Ice default constructor called" << RST << std::endl;
}

/*
 * Ice copy constructor
 */
Ice::Ice(Ice const &copy): AMateria()
{
	std::cout << BLUE << "Ice copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * Ice assignation operator overload
 */
Ice& Ice::operator=(Ice const &src)
{
	std::cout << BLUE << "Ice addignation operator called" << RST << std::endl;
	this->type = src.type;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Duplicates materia
 */
Ice* Ice::clone(void) const
{
	return (new Ice());
}

/*
 * Casts a spell
 *
 * @param target target of the spell
 */
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}