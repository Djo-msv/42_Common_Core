#include "Fixed.hpp"
#include "Point.hpp"

Fixed cross_vec(Point vec1, Point vec2)
{
	return ((vec1.get_x_value() * vec2.get_y_value())
		- (vec1.get_y_value() * vec2.get_x_value()));
}

int	check_dot(Point vec, Point point, Point vec_point)
{
	Fixed	value = 0;
	Point	dot_vec(vec_point, point);

	value = cross_vec(vec, dot_vec);
	if (value > 0)
		return (1);
	if (value < 0)
		return (-1);
	return (0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int		side;
	Point	vecAB(a, b);
	Point	vecBC(b, c);
	Point	vecCA(c, a);
	
	side = check_dot(vecAB, point, a);
	if (side == 0)
		return (0);
	if (check_dot(vecBC, point, b) != side)
		return (0);
	if (check_dot(vecCA, point, c) != side)
		return (0);
	return (1);
}
