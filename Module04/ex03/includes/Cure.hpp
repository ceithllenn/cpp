#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

class Cure: virtual public AMateria
{
	private:

	public:
			Cure();
			Cure(Cure const &copy);
			Cure& operator=(Cure const &src);

			~Cure();

			Cure* clone() const;
			void use(ICharacter& target);
};