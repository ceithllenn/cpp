#include "ClapTrap.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * ClapTrap destructor
 */
ClapTrap::~ClapTrap()
{
	std::cout << COL << "ClapTrap destructor called" << RESET << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * ClapTrap default constructor
 */
ClapTrap::ClapTrap(): name("ClapTrap"), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << COL << "ClapTrap default constructor called" << RESET << std::endl;
}

/*
 * ClapTrap name constructor
 */
ClapTrap::ClapTrap(std::string s): name(s), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << COL << "ClapTrap " << name << " was created" << RESET << std::endl;
}

/*
 * ClapTrap copy constructor
 */
ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << COL << "ClapTrap copy constructor called" << RESET << std::endl;
	*this = copy;
}

/*
 * ClapTrap assignation operator overload
 */
ClapTrap& ClapTrap::operator=(ClapTrap const &copy)
{
	std::cout << COL << "ClapTrap assignation operator called" << std::endl;
	this->name = copy.name;
	this->hit_point = copy.hit_point;
	this->energy_point = copy.energy_point;
	this->attack_damage = copy.attack_damage;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes the ClapTrap attack if he has at least one energy point and one hit point
 *
 * @param target target of the attack
 */
void ClapTrap::attack(const std::string& target)
{
	if (this->energy_point > 0 && this->hit_point > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_point--;
	}
	else if (this->energy_point == 0)
		std::cout << RED << "ClapTrap " << this->name << " is not able to attack " << target << " because he has not energy points left!" << RESET << std::endl;
	else
		std::cout << RED << "ClapTrap " << this->name << " is not able to attack " << target << " because he has not hit points left!" << RESET << std::endl;
}

/*
 * Makes the ClapTrap take damage
 *
 * @param amount amount of damage taken
 */
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_point > amount)
		this->hit_point -= amount;
	else if (this->hit_point > 0)
		this->hit_point = 0;
	else
	{
		std::cout << "ClapTrap " << this->name << " is already dead! :(" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, he now has " << this->hit_point << " hit points left." << std::endl;
}

/*
 * Makes the ClapTrap repair itself
 *
 * @param amount amount of hit points healed
 */
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point > 0 && this->hit_point > 0 && this->hit_point + amount <= 10)
	{
		this->hit_point += amount;
		std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " hit points. He now has " << this->hit_point << " hit points." << std::endl;
		this->energy_point--;
	}
	else if (this->energy_point == 0)
		std::cout << RED << "ClapTrap " << this->name << " is not able to repair itself because he doesn't have enough energy points." << RESET << std::endl;
	else if (this->hit_point == 0)
		std::cout << RED << "ClapTrap " << this->name << " is not able to repair itself because he doesn't have enough hit points." << RESET << std::endl;
	else
		std::cout << RED << "ClapTrap " << this->name << " can't be repaired to have more than 10 hit points." << RESET << std::endl;
}
