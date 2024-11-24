#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie	*zombie;

	zombie = newZombie("Bernard");
	std::cout << "------ Out of newZombie ------" << std::endl;
	if (!zombie)
		return (0);
	randomChump("Bob");
	std::cout << "------ Out of randomChump ------" << std::endl;
	zombie->announce();
	delete zombie;
	return (0);
}