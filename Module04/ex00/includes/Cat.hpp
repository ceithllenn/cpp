#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: virtual public Animal
{
	public:
			Cat();
			Cat(Cat const &copy);
			Cat &operator=(Cat const &src);

			~Cat();

			void makeSound() const;
};

#endif