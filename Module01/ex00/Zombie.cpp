#include "Zombie.hpp"
#include <iostream>

/*
 * Zombie constructor
 */
Zombie::Zombie(std::string name) : name(name)
{
	std::cout
			<< "created a new Zombie named " << name
			<< std::endl;
}

/*
 * Zombie destructor
 */
Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << " was destroyed" << std::endl;
}

/*
 * Zombie announces himself
 */
void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}
