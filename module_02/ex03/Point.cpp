#include "Point.hpp"

Point::Point() : m_y(0), m_x(0) {}

Point::Point(const float x, const float y) : m_x(x), m_y(y) {}

Point::Point(const Point &src) {
	*this = src;}

Point::~Point() {}

Point & Point::operator=(const Point &rhs) {
	if (this != &rhs)
	{
		(Fixed)m_x = (Fixed)rhs.getX();
		(Fixed)m_y = (Fixed)rhs.getY();
	}
	return *this;}

Fixed Point::getX() const {
	return m_x;}

Fixed Point::getY() const {
	return m_y;}
