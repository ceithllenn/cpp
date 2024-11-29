#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	public:
			virtual ~IMateriaSource() {};
			virtual void learnMateria(AMateria *src) = 0;
			virtual AMateria* createMateria(const std::string &type) = 0;
};
