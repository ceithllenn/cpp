#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define GREEN   "\033[32m"

class FragTrap: virtual public ClapTrap
{
	private:

	public:
			FragTrap();
			FragTrap(std::string name);
			FragTrap(const FragTrap &copy);

			FragTrap &operator=(const FragTrap &src);

			virtual ~FragTrap();

			void highFiveGuys();
};

#endif