#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap	a;
	FragTrap	b("Bob");

	b.attack("some bad robot");
	b.highFiveGuys();
	b.takeDamage(10);
	a.attack("some bad robot");
	return (0);
}
