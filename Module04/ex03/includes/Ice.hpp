#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"

class Ice: virtual public AMateria
{
	private:

	public:
			Ice();
			Ice(Ice const &copy);
			Ice& operator=(Ice const &src);

			~Ice();

			Ice* clone() const;
			void use(ICharacter& target);
};
