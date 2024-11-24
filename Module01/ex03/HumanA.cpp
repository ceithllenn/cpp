#include "HumanA.hpp"
#include <iostream>

/*
 * HumanA constructor
 */
HumanA::HumanA(std::string s, Weapon &weapon): name(s), weapon(weapon)
{

}

/*
 * HumanA destructor
 */
HumanA::~HumanA()
{

}

/*
 * Makes the HumanA attack
 */
void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << this->weapon.getType();
	std::cout << std::endl;
}
