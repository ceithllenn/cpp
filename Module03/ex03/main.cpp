#include "DiamonTrap.hpp"

int main()
{
	DiamondTrap	a;
	DiamondTrap	b("Bob");
	DiamondTrap	c(a);

	a.attack("some bad robot");
	a.whoAmI();
	b.whoAmI();
	b.takeDamage(95);
	b.beRepaired(5);
	c.whoAmI();
	b.attack("some bad robot");

	return (0);
}
