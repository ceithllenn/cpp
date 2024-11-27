#include "DiamonTrap.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * DiamondTrap destructor
 */
DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "DiamondTrap destructor called" << RESET << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * DiamondTrap default constructor
 */
DiamondTrap::DiamondTrap(): ClapTrap("DiamondTrap_clap_trap")
{
	this->name = "DiamondTrap";
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << YELLOW << "DiamondTrap default constructor called" << RESET << std::endl;
}

/*
 * DiamondTrap name constructor
 */
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->name = name;
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << YELLOW << "DiamondTrap " << name << " was created" << RESET << std::endl;
}

/*
 * DiamonTrap copy constructor
 */
DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << YELLOW << "DiamondTrap copy constructor called" << RESET << std::endl;
}

/*
 * DiamondTrap assignation operator overload
 */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << YELLOW << "DiamondTrap assignation operator called" << RESET << std::endl;
	this->name = src.name + "_clap_trap";
	this->hit_point = src.hit_point;
	this->energy_point = src.energy_point;
	this->attack_damage = src.attack_damage;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Makes the DiamondTrap attack if he has at least one energy point and one hit point
 *
 * @param target target of the attack
 */
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/*
 * Makes the DiamondTrap introduce himself
 */
void DiamondTrap::whoAmI(void)
{
	std::cout << "I'm a DiamondTrap called " << this->name	
				<< " but I'm also a ClapTrap called " << ClapTrap::name
				<< " and this is very confusing me." << std::endl;
}
