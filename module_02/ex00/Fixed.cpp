#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : m_nb(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	m_nb = src.getRawBits();
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

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return m_nb;
}

void Fixed::setRawBits( int const raw )
{
	m_nb = raw;
}
