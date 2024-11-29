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
	for (int i = 0; i < 4; i++)
	{
		if (inv[i])
			delete inv[i];
	}
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
Character::Character(Character const &copy): name(copy.getName() + "_copy")
{
	std::cout << PINK << "Character copy constructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inv[i])
			this->inv[i] = copy.inv[i]->clone();
		else
			this->inv[i] = NULL;
	}
}

/*
 * Character assignation operator overload
 */
Character& Character::operator=(Character const &src)
{
	std::cout << PINK << "Character assignation operator called" << RST << std::endl;
	this->name = src.name;
	for (int i = 0; i < 4; i++)
	{
		if (!src.inv[i])
			inv[i] = NULL;
		else
			inv[i] = src.inv[i]->clone();
	}
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

std::string const &Character::getName(void) const
{
	return (this->name);
}

AMateria* Character::getMateria(int idx) const
{
	if (inv[idx])
		return (inv[idx]);
	return (NULL);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Equips a materia if there is a empty spot in inventory
 *
 * @param m materia to be equipped
 */
void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inv[i])
		{
			inv[i] = m;
			std::cout << PINK << name << " equipped " << m->getType() << RST << std::endl;
			return ;
		}
	}
	std::cout << REDD << name << " has no space left for " << m->getType() << RST << std::endl;
}

/*
 * Unequips a materia
 *
 * @param idx slot in Character's inventory that will be emptied
 */
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << REDD << name << " has no materia equipped in slot " << idx << RST << std::endl;
		return ;
	}
	if (inv[idx])
	{
		std::cout << PINK << name << " removed " << inv[idx]->getType() << " materia from his inventory" << RST << std::endl;
		inv[idx] = NULL;
		return ;
	}
	std::cout << REDD << name << " has no materia equipped in slot " << idx << RST << std::endl;
}

/*
 * Uses a materia
 *
 * @param idx index of the materia to be used in Character's inventory
 * @param target target of the spell
 */
void Character::use(int idx, ICharacter &target)
{
	if (inv[idx])
	{
		inv[idx]->use(target);
		return ;
	}
	std::cout << REDD << name << " has no materia equipped in slot " << idx << RST << std::endl;
}