#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define BLUE    "\033[34m"

class ScavTrap: virtual public ClapTrap
{
	private:
			bool	gate_keeper;

	public:
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &copy);

			ScavTrap &operator=(const ScavTrap &src);

			virtual ~ScavTrap();

			void attack(const std::string &target);
			void guardGate();
};

#endif