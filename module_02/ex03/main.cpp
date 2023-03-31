#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
	Point a(-2, 1);
	Point b(3, 2);
	Point c(1, 5);

	Point p1(2, 3);
	Point p2(1, 4);
	Point p3(3, 3);

	std::cout << bsp(a, b, c, p1) << std::endl;
	std::cout << bsp(a, b, c, p2) << std::endl;
	std::cout << bsp(a, b, c, p3) << std::endl;
	return 0;
}