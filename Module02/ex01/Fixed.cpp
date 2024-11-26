#include "Fixed.hpp"

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
 * Fixed int constructor
 */
Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	value = n << fract;
}

/*
 * Fixed float constructor
 */
Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	value = (int)roundf(n * (1 << fract));
}

/*
 * Returns the value of a Fixed number
 */
int Fixed::getRawBits(void) const
{
	return (value);
}

/*
 * Sets the value of a Fixed number
 *
 * @param raw Fixed number value
 */
void Fixed::setRawBits(int const raw)
{
	value = raw;
}

/*
 * Converts Fixed value into float
 */
float Fixed::toFloat(void) const
{
	return ((float)value / (float)(1 << fract));
}

/*
 * Converts Fixed value into int
 */
int Fixed::toInt(void) const
{
	return ((int)value >> fract);
}

/*
 * Operator << overload for Fixed
 * Displays the Fixed number converted in float
 */
std::ostream& operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
