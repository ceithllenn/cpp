#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

#define RESET "\033[0m"
#define COL "\033[35m"
#define RED "\033[31m"

class ClapTrap
{
	protected:
			std::string				name;
			unsigned int			hit_point;
			unsigned int			energy_point;
			int						attack_damage;

	public:
			ClapTrap();
			~ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(ClapTrap const &copy);

			ClapTrap& operator=(ClapTrap const &copy);

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
};

#endif