#include "AMateria.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * AMateria destructor
 */
AMateria::~AMateria()
{
	std::cout << IVRY << "AMateria destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * AMateria default constructor
 */
AMateria::AMateria(): type("no type")
{
	std::cout << IVRY << "AMateria default constructor called" << RST << std::endl;
}

/*
 * AMateria type constructor
 */
AMateria::AMateria(std::string const &s): type(s)
{
	std::cout << IVRY << s << " AMateria was created" << RST << std::endl;
}

/*
 * AMateria copy constructpr
 */
AMateria::AMateria(AMateria const &copy)
{
	std::cout << IVRY << "AMateria copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * AMateria assignation operator overload
 */
AMateria& AMateria::operator=(AMateria const &src)
{
	this->type = src.type;
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

std::string const &AMateria::getType() const
{
	return (this->type);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Uses materia
 *
 * @param target target of the spell
 */
void AMateria::use(ICharacter& target)
{
	std::cout << IVRY << "Default attack (no type) on " << target.getName() << RST << std::endl;
}