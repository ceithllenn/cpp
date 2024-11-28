#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: virtual public Animal
{
	private:
			Brain* brain;
	public:
			Dog();
			Dog(Dog const &copy);
			Dog& operator=(Dog const &src);

			~Dog();

			Brain* getBrain() const;

			void makeSound() const;
};

#endif