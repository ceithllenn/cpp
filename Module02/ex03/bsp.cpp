#include "Point.hpp"

/*
 * Calculates the area of a triangle
 * area = (1x(2y - 3y) + 2x(3y - 1y) + 3x(1y - 2y)) / 2
 *
 * @return area * 2
 */
static float get_area(const Point p1, const Point p2, const Point p3)
{
	float	area;

	area = (p1.get_x() * (p2.get_y() - p3.get_y())
			+ p2.get_x() * (p3.get_y() - p1.get_y())
			+ p3.get_x() * (p1.get_y() - p2.get_y()));

	if (area >= 0)
		return (area);
	return (area * -1);
}

/*
 * Checks if a point is inside a triange
 *
 * Splits abc triangle into three triangles pab, pbc, pac
 * and calculates their areas
 * If abc's area equals the sum of the three triangles' area
 * then the point is inside the triangle
 * 
 * @param point point
 * @param a triangle vertex
 * @param b triangle vertex
 * @param c triangle vertex
 * @return true if point is inside, false is it isn't
 */
bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float a0, a1, a2, a3;

	a0 = get_area(a, b, c);
	a1 = get_area(point, a, b);
	a2 = get_area(point, b, c);
	a3 = get_area(point, a, c);

	if (!a1 || !a2 || !a3)
		return (false);
	if (a1 + a2 + a3 == a0)
		return (true);
	return (false);
}
