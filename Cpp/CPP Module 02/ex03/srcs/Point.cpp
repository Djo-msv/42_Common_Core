#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void): _x(0), _y(0)
{}

Point::Point(const float x, const float y): _x(x), _y(y)
{}

Point::Point(const int x, const int y): _x(x), _y(y)
{}

Point::Point(const Point &value): _x(value._x), _y(value._y)
{}

Point::Point(const Point a, const Point b)
    : _x(b.get_x_value() - a.get_x_value()),
      _y(b.get_y_value() - a.get_y_value())
{}

Point::~Point(void){}

const Fixed &Point::get_x_value(void) const
{
	return (_x);
}

const Fixed &Point::get_y_value(void) const
{
	return (_y);
}

Point &Point::operator=(const Point &value)
{
	(void)value;
	return *this;
}
