#include "Fixed.hpp"
#include <iostream>

int Fixed::fract = 8;

/*
 * Fixed default constructor
 */
Fixed::Fixed(): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
 * Fixed destructor
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * Fixed copy constructor
 */
Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/*
 * Fixed copy assignment operator overload
 */
Fixed& Fixed::operator=(Fixed const &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
		value = copy.getRawBits();
	return (*this);
}

/*
 * Returns the value of a Fixed number
 */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

/*
 * Sets the value of a Fixed number
 *
 * @param raw Fixed number value
 */
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}
