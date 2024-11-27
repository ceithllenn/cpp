#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class Animal
{
	protected:
			std::string type;

	public:
			Animal();
			Animal(std::string s);
			Animal(const Animal &copy);
			Animal &operator=(const Animal &src);

			virtual ~Animal();

			virtual void makeSound() const;
};

#endif