#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public :
		Point();
		Point(const float x, const float y);
		Point(const int x, const int y);
		Point(const Point a, const Point b);
		Point(const Point &value);
		~Point();

		const Fixed& get_x_value(void) const;
		const Fixed& get_y_value(void) const;

		Point& operator=(const Point& value);

	private :
		const Fixed	_x;
		const Fixed	_y;
};

Fixed	cross_vec(Point vec1, Point vec2);

#endif
