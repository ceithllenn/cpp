#include "Fixed.hpp"

/*STATIC VARIABLE*/
int Fixed::fract = 8;

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Fixed destructor
 */
Fixed::~Fixed()
{
//	std::cout << BLUE << "Fixed destructor called" << RESET << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Fixed default constructor
 */
Fixed::Fixed(): value(0)
{
//	std::cout << BLUE << "Fixed default constructor called" << RESET << std::endl;
}

/*
 * Fixed copy constructor
 */
Fixed::Fixed(Fixed const &copy)
{
//	std::cout << BLUE << "Fixed copy constructor called" << RESET << std::endl;
	*this = copy;
}

/*
 * Fixed int constructor
 */
Fixed::Fixed(int const n)
{
//	std::cout << BLUE << "Fixed int constructor called" << RESET << std::endl;
	value = n << fract;
}

/*
 * Fixed float constructor
 */
Fixed::Fixed(float const n)
{
//	std::cout << BLUE << "Fixed float constructor called" << RESET << std::endl;
	value = (int)roundf(n * (1 << fract));
}

/*
 * Fixed copy assignment operator overload
 */
Fixed& Fixed::operator=(Fixed const &copy)
{
//	std::cout << BLUE << "Fixed assignation operator called" << RESET << std::endl;
	if (this != &copy)
		value = copy.getRawBits();
	return (*this);
}

/**************************************************************************/
/*						COMPARISON OPERATORS OVERLOAD		   			  */
/**************************************************************************/

/*
 * Fixed > operator overload
 */
bool Fixed::operator>(Fixed const fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

/*
 * Fixed < operator overload
 */
bool Fixed::operator<(Fixed const fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

/*
 * Fixed >= operator overload
 */
bool Fixed::operator>=(Fixed const fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

/*
 * Fixed <= operator overload
 */
bool Fixed::operator<=(Fixed const fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

/*
 * Fixed == operator overload
 */
bool Fixed::operator==(Fixed const fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

/*
 * Fixed != operator overload
 */
bool Fixed::operator!=(Fixed const fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

/**************************************************************************/
/*						ARITHMETIC OPERATORS OVERLOAD		   			  */
/**************************************************************************/

/*
 * Fixed + operator overload
 */
float Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

/*
 * Fixed - operator overload
 */
float Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

/*
 * Fixed * operator overload
 */
float Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

/*
 * Fixed / operator overload
 */
float Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

/**************************************************************************/
/*						INCREMENT OPERATORS OVERLOAD		   			  */
/**************************************************************************/
/*
 * Fixed pre-increment overload
 */
Fixed Fixed::operator++()
{
	this->value++;
	return (*this);
}

/*
 * Fixed pre-decrement overload
 */
Fixed Fixed::operator--()
{
	this->value--;
	return (*this);
}

/*
 * Fixed post-increment overload
 */
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->value;
	return (tmp);
}

/*
 * Fixed post-decrement overload
 */
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->value;
	return (tmp);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/
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
 * @return minimal value between first and second
 */
Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	return (second);
}

/*
 * @return minimal value between first and second
 */
const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	return (second);
}

/*
 * @return maximal value between first and second
 */
Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}

/*
 * @return maximal value between first and second
 */
const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
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
