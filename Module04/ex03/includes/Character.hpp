#pragma once

#include "ICharacter.hpp"

class Character: virtual public ICharacter
{
	private:
			std::string name;
			AMateria*	inv[4];
	
	public:
			Character();
			Character(std::string s);
			Character(Character const &copy);
			Character& operator=(Character const &src);

			~Character();

			std::string const &getName() const;
			AMateria* getMateria(int idx) const;
			void equip(AMateria *m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);
};
