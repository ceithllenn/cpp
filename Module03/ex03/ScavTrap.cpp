#include "ScavTrap.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * ScavTrap Destructor
 */
ScavTrap::~ScavTrap()
{
	std::cout << BLUE << "ScavTrap destructor called" << RESET << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * ScavTrap default constructor
 */
ScavTrap::ScavTrap(): ClapTrap("ScavTrap")
{
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	this->gate_keeper = false;
	std::cout << BLUE << "ScavTrap default constructor called" << RESET << std::endl;
}

/*
 * ScavTrap name constructor
 */
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	this->gate_keeper = false;
	std::cout << BLUE << "ScavTrap " << name << " was created" << RESET << std::endl;
}

/*
 * ScavTrap copy constructor
 */
ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	this->gate_keeper = copy.gate_keeper;
	std::cout << BLUE << "ScavTrap copy constructor called" << RESET << std::endl;
}

/*
 * ScavTrap assignation operator overload
 */
ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << BLUE << "ScavTrap assignation operator called" << RESET << std::endl;
	this->name = src.name;
	this->hit_point = src.hit_point;
	this->energy_point = src.energy_point;
	this->attack_damage = src.attack_damage;
	this->gate_keeper = src.gate_keeper;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes the ScavTrap attack if he has at least one energy point and one hit point
 *
 * @param target target of the attack
 */
void ScavTrap::attack(const std::string& target)
{
	if (this->energy_point > 0 && this->hit_point > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_point--;
	}
	else if (this->energy_point == 0)
		std::cout << RED << "ScavTrap " << this->name << " is not able to attack " << target << " because he has not energy points left!" << RESET << std::endl;
	else
		std::cout << RED << "ScavTrap " << this->name << " is not able to attack " << target << " because he has not hit points left!" << RESET << std::endl;
}

/*
 * Switches the ScavTrap in gate keeper mode
 */
void ScavTrap::guardGate(void)
{
	if (this->gate_keeper)
		std::cout << RED << "ScavTrap " << this->name << " is already guarding the gate!" << RESET << std::endl;
	else
	{
		this->gate_keeper = true;
		std::cout << "ScavTrap " << this->name << " is now guarding the gate!" << std::endl;
	}
}
