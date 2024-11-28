#include "Character.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Character destructor
 */
Character::~Character()
{
	std::cout << PINK << "Character destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Character default constructor
 */
Character::Character()
{
	std::cout << PINK << "Character default constructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}

/*
 * Character name constructor
 */
Character::Character(std::string s): name(s)
{
	std::cout << PINK << "A Character called " << s << " was created" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}

/*
 * Character copy constructor
 */
Character::Character(Character const &copy)
{
	std::cout << PINK << "Character copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * Character assignation operator overload
 */
Character& Character::operator=(Character const &src)
{
	std::cout << PINK << "Character assignation operator called" << RST << std::endl;
	this->name = src.name;
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

std::string const &Character::getName(void) const
{
	return (this->name);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

void Character::equip(AMateria *m) const
{
	for (int i = 0; i < 4; i++)
	{
		if (!inv[i])
		{
			inv[i] = m;

		}
	}

}