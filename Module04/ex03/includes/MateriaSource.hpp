#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

class MateriaSource: virtual public IMateriaSource
{
	private:
			AMateria*	tab[4];

	public:
			MateriaSource();
			MateriaSource(MateriaSource const &copy);
			MateriaSource& operator=(MateriaSource const &src);

			~MateriaSource();

			void learnMateria(AMateria *materia);
			AMateria* createMateria(std::string const &type);
};
