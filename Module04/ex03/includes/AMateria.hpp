#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "colors.hpp"
# include "ICharacter.hpp"

class AMateria
{
	protected:
			std::string type;
	public:
			AMateria();
			AMateria(std::string const &type);
			AMateria(AMateria const &copy);
			AMateria& operator=(AMateria const &src);

			virtual ~AMateria();

			std::string const &getType() const;
			virtual AMateria *clone() const = 0;
			virtual void use(ICharacter& target);
};

#endif