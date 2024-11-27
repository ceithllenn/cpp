#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a;
	ClapTrap	b("Bob");

	b.attack("some bad robot");
	b.takeDamage(10);
	b.takeDamage(10);
	b.beRepaired(10);
	a.takeDamage(5);
	a.beRepaired(4);
	for (int i = 0; i < 10; i++)
		a.attack("some bad robot");
	return (0);
}