#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: virtual public Animal
{
	private:
			Brain* brain;

	public:
			Cat();
			Cat(Cat const &copy);
			Cat &operator=(Cat const &src);

			~Cat();

			Brain* getBrain() const;

			void makeSound() const;
};

#endif