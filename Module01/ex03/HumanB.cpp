#include "HumanB.hpp"
#include <iostream>

/*
 * HumanB constructor
 */
HumanB::HumanB(std::string s): name(s), weapon(NULL)
{

}

/*
 * HumanB destructor
 */
HumanB::~HumanB()
{

}

/*
 * Gives a new weapon to HumanB
 *
 * @param weapon new weapon
 */
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

/*
 * Makes the HumanB attack
 */
void HumanB::attack(void)
{
	if (!weapon)
		std::cout << name << " doesn't have a weapon, he attacks with his fists !" << std::endl;
	else
	{
		std::cout
				<< name
				<< " attacks with their "
				<< weapon->getType()
				<< std::endl;
	}
}
