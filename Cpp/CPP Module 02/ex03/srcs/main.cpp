#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
    os << value.toFloat();
    return os;
}

int	main(void)
{
	{
		bool is_inside;

		Point a(2, 4);
		Point b(1, 0);
		Point c(-3, -1);
		Point point(0, 0);

		is_inside = bsp(a, b, c, point);
		if (is_inside)
			std::cout << "the point " << point.get_x_value() << "-" <<  point.get_y_value() << " is inside" << std::endl;
		else
			std::cout << "the point is outside" << std::endl;
	}
	{
		bool is_inside;

		Point a(2, 4);
		Point b(1, 0);
		Point c(-3, -1);
		Point point(0, 1);

		is_inside = bsp(a, b, c, point);
		if (is_inside)
			std::cout << "the point " << point.get_x_value() << "-" <<  point.get_y_value() << " is inside" << std::endl;
		else
			std::cout << "the point is outside" << std::endl;
	}
	{
		bool is_inside;

		Point a(2, 4);
		Point b(1, 0);
		Point c(-3, -1);
		Point point(0, -1);

		is_inside = bsp(a, b, c, point);
		if (is_inside)
			std::cout << "the point " << point.get_x_value() << "-" <<  point.get_y_value() << " is inside" << std::endl;
		else
			std::cout << "the point is outside" << std::endl;
	}
	{
		bool is_inside;

		Point a(2, 4);
		Point b(1, 0);
		Point c(-3, -1);
		Point point(1, 0);

		is_inside = bsp(a, b, c, point);
		if (is_inside)
			std::cout << "the point " << point.get_x_value() << "-" <<  point.get_y_value() << " is inside" << std::endl;
		else
			std::cout << "the point is outside" << std::endl;
	}
	return (0);

}
