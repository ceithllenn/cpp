#include "Point.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Point destructor
 */
Point::~Point()
{
//	std::cout << COL << "Point destructor called" << RESET << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Point default constructor
 */
Point::Point(): x(0), y(0)
{
	std::cout << COL << "Point default constructor called: " << RESET << std::endl;
}

/*
 * Point copy constructor
 */
Point::Point(Point const &copy): x(copy.get_x()), y(copy.get_y())
{
//	std::cout << COL << "Point copy constructor called: " << RESET << std::endl;
}

/*
 * Point float constructor
 */
Point::Point(Fixed const x, Fixed const y): x(x), y(y)
{
//	std::cout << COL << "Point fixed constructor called: " << RESET << std::endl;
}

/*
 * Fixed copy assignment operator overload
 */
Point& Point::operator=(Point const &copy)
{
	//std::cout << COL << "Point assignation operator called" << RESET << std::endl;
	(void)copy;
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Returns x value
 */
float Point::get_x(void) const
{
	return (x.toFloat());
}

/*
 * Return y value
 */
float Point::get_y(void) const
{
	return (y.toFloat());
}
