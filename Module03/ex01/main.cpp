#include "ScavTrap.hpp"

int main()
{
	ScavTrap	a;
	ScavTrap	b("Bob");

	b.attack("some bad robot");
	b.guardGate();
	b.guardGate();
	b.takeDamage(10);
	a.attack("some bad robot");
}