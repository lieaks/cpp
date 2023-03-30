#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	~Point();
	Point& operator=(const Point &rhs);
	Fixed getX() const;
	Fixed getY() const;

	private:
	const Fixed m_x;
	const Fixed m_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP