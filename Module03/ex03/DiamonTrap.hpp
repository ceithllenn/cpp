#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

#define YELLOW  "\033[33m"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
			std::string name;

	public:
			DiamondTrap();
			DiamondTrap(std::string name);
			DiamondTrap(const DiamondTrap &copy);

			DiamondTrap &operator=(const DiamondTrap &src);

			virtual ~DiamondTrap();

			void attack(const std::string &target);
			void whoAmI();
};

#endif