#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

#define COL "\033[35m"

class Point
{
	private:
			Fixed const x;
			Fixed const y;

	public:
			Point();
			~Point();
			Point(Fixed const x, Fixed const y);
			Point(Point const &copy);

			Point& operator=(Point const &copy);

			float get_x() const;
			float get_y() const;
};

#endif