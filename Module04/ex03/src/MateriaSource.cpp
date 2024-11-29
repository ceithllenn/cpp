#include "MateriaSource.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * MateriaSource destructor
 */
MateriaSource::~MateriaSource()
{
	std::cout << PURP << "MateriaSource destructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (tab[i])
			delete tab[i];
	}
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * MateriaSource default constructor
 */
MateriaSource::MateriaSource()
{
	std::cout << PURP << "MateriaSource default constructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		tab[i] = NULL;
}

/*
 * MateriaSource copy constructor
 */
MateriaSource::MateriaSource(MateriaSource const &copy): IMateriaSource()
{
	std::cout << PURP << "MateriaSource copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * MateriaSource assignation operator overload
 */
MateriaSource& MateriaSource::operator=(MateriaSource const &src)
{
	std::cout << PURP << "MateriaSource assignation operator called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (tab[i])
			delete tab[i];
		if (!src.tab[i])
			tab[i] = NULL;
		else
			tab[i] = src.tab[i]->clone();
	}
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Learns a materia
 *
 * @param materia materia to be learned
 */
void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!tab[i])
		{
			tab[i] = materia;
			return ;
		}
	}
}

/*
 * Creates a materia
 *
 * @param type type of the materia that will be created
 *
 * @return new materia
 */
AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (tab[i]->getType() == type)
			return (tab[i]->clone());
	}
	return (NULL);
}
