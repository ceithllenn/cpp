#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *zombie;

	zombie = new Zombie(name);
	if (!zombie)
		return (NULL);
	return (zombie);
}
