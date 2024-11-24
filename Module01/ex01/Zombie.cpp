#include "Zombie.hpp"
#include <iostream>

/*
 * Zombie default constructor
 */
Zombie::Zombie(): name("Zombie")
{
	//std::cout << "default constructor created a new zombie" << std::endl;
}

/*
 * Zombie constructor
 */
Zombie::Zombie(std::string name): name(name)
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

/*
 * @param name name of the zombie
 */
void Zombie::set_name(std::string s)
{
	name = s;
}
