#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
	public:
			WrongCat();
			WrongCat(WrongCat const &copy);
			WrongCat& operator=(WrongCat const &src);

			~WrongCat();

			void makeSound() const;
};

#endif