#include "FragTrap.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * FragTrap deconstructor
 */
FragTrap::~FragTrap()
{
	std::cout << GREEN << "FragTrap deconstructor called" << RESET << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * FragTrap default constructor
 */
FragTrap::FragTrap(): ClapTrap("FragTrap")
{
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << GREEN << "FragTrap default constructor called" << RESET << std::endl;
}

/*
 * FragTrap name constructor
 */
FragTrap::FragTrap(std::string s): ClapTrap(s)
{
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << GREEN << "FragTrap " << s << "was created" << RESET << std::endl;
}

/*
 * FragTrap copy constructor
 */
FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << GREEN << "FragTrap copy constructor called" << RESET << std::endl;
}

/*
 * FragTrap assignation operator overload
 */
FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << GREEN << "FragTrap assignation operator called" << RESET << std::endl;
	this->name = src.name;
	this->hit_point = src.hit_point;
	this->energy_point = src.energy_point;
	this->attack_damage = src.attack_damage;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes the FragTrap demand a high five
 */
void FragTrap::highFiveGuys(void)
{
	std::cout << "Robots high five !!" << std::endl;
}
