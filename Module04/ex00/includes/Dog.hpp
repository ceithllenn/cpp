#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: virtual public Animal
{
	public:
			Dog();
			Dog(Dog const &copy);
			Dog& operator=(Dog const &src);

			~Dog();

			void makeSound() const;
};

#endif