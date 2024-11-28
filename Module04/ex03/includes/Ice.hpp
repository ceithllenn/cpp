#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"

class Ice: virtual public AMateria
{
	private:

	public:
			Ice();
			Ice(std::string type);
			Ice(Ice const &copy);
			Ice& operator=(Ice const &src);

			~Ice();

			Ice* clone() const;
			void use(ICharacter& target);
};

#endif