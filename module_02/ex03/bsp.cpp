#include "Point.hpp"

static Fixed area( Point const a, Point const b, Point const c )
{
	return (((a.getX() * (b.getY() - c.getY())) + 
			 (b.getX() * (c.getY() - a.getY())) + 
			 (c.getX() * (a.getY() - b.getY()))) / 2);
}

static Fixed abs_value(Fixed value)
{
	if (value < 0)
		return value * -1;
	return value;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) 
{
	Fixed abc(abs_value(area(a, b, c)));
	Fixed pbc(abs_value(area(point, b, c)));
	Fixed apc(abs_value(area(a, point, c)));
	Fixed abp(abs_value(area(a, b, point)));

	return (abc == pbc + apc + abp);
}