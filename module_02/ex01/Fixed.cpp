#include "Fixed.hpp"
#include <iostream>

static const int m_fractBits = 8;

Fixed::Fixed() : m_nb(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb) : m_nb(nb << m_fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const double nb) : m_nb(nb * (1 << m_fractBits))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		setRawBits(src.getRawBits());
	return *this;
}

::Fixed & operator << (const Fixed &rhs)
{

}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return m_nb;
}

void Fixed::setRawBits( int const raw )
{
	m_nb = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)m_nb / (float)(1 << m_fractBits)); 
}

int Fixed::toInt( void ) const
{
	return getRawBits() >> m_fractBits;
}