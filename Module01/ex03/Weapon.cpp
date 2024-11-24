#include "Weapon.hpp"

/*
 * Weapon default constructor
 */
Weapon::Weapon(): type("Some other type of club")
{

}

/*
 * Weapon constructor
 */
Weapon::Weapon(std::string s): type(s)
{

}

/*
 * Weapon destructor
 */
Weapon::~Weapon()
{

}

/*
 * @return reference to the type of Weapon
 */
std::string const &Weapon::getType(void) const
{
	return (this->type);
}

/*
 * Changes the weapon type
 *
 * @param s new type
 */
void Weapon::setType(std::string s)
{
	type = s;
}
