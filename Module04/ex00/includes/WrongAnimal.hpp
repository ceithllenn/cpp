#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class WrongAnimal
{
	protected:
			std::string type;

	public:
			WrongAnimal();
			WrongAnimal(std::string s);
			WrongAnimal(WrongAnimal const &copy);
			WrongAnimal& operator=(WrongAnimal const &src);

			virtual ~WrongAnimal();

			void makeSound() const;
};

#endif