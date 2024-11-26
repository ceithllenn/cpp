#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main()
{
	Point a(0, 0), b(4, 0), c(0, 4);

	if (bsp(a, b, c, Point(1, 1))) //in
		std::cout << "P(1, 1) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(1, 1) is outside ABC triangle" << std::endl;
	if (bsp(a, b, c, Point(5, 5))) //out
		std::cout << "P(5, 5) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(5, 5) is outside ABC triangle" << std::endl;
	if (bsp(a, b, c, Point(0, 4))) //out
		std::cout << "P(0, 4) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(0, 4) is outside ABC triangle" << std::endl;

	Point a1(0, 0), b1(4, 0), c1(2, 3.464f);

	if (bsp(a1, b1, c1, Point(2, 1))) //in
		std::cout << "P(2, 1) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(2, 1) is outside ABC triangle" << std::endl;
	if (bsp(a1, b1, c1, Point(5, 2))) //out
		std::cout << "P(5, 2) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(5, 2) is outside ABC triangle" << std::endl;
	if (bsp(a1, b1, c1, Point(3, 1.732f))) //out
		std::cout << "P(3, 1.732) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(3, 1.732) is outside ABC triangle" << std::endl;

	Point a2(1, 1), b2(6, 1), c2(4, 5);
	if (bsp(a2, b2, c2, Point(4, 2))) //in
		std::cout << "P(4, 2) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(4, 2) is outside ABC triangle" << std::endl;
	if (bsp(a2, b2, c2, Point(7, 4))) //out
		std::cout << "P(7, 4) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(7, 4) is outside ABC triangle" << std::endl;
	if (bsp(a2, b2, c2, Point(6, 1))) //out
		std::cout << "P(6, 1) is inside ABC triangle" << std::endl;
	else
		std::cout << "P(6, 1) is outside ABC triangle" << std::endl;

	return (0);
}

