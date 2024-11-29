#include "Cure.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Cure destructor
 */
Cure::~Cure()
{
	std::cout << GRNN << "Cure destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Cure default constructor
 */
Cure::Cure(): AMateria("cure")
{
	std::cout << GRNN << "Cure default constructor called" << RST << std::endl;
}

/*
 * Cure copy constructor
 */
Cure::Cure(Cure const &copy): AMateria()
{
	std::cout << GRNN << "Cure copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * Cure assignation operator overload
 */
Cure& Cure::operator=(Cure const &src)
{
	std::cout << GRNN << "Cure assignation operator called" << RST << std::endl;
	this->type = src.type;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Duplicates materia
 */
Cure* Cure::clone(void) const
{
	return (new Cure());
}

/*
 * Casts a spell
 *
 * @param target target of the spell
 */
void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
