#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// CONSTRUCTORS
Fixed::Fixed() : m_nb(0){}

Fixed::Fixed(const int nb) : m_nb(nb << m_fractBits){}

Fixed::Fixed(const float nb) : m_nb(roundf( nb * (1 << m_fractBits))){}

Fixed::Fixed(const Fixed &src){
	*this = src;}

// DESTRUCTORS
Fixed::~Fixed() {}

// OPERATORS
Fixed& Fixed::operator= (const Fixed &src) {
	if (this != &src)
		setRawBits(src.getRawBits());
	return *this;}

bool Fixed::operator> (const Fixed &rhs) const{
	return m_nb < rhs.getRawBits();}

bool Fixed::operator< (const Fixed &rhs) const{
	return m_nb < rhs.getRawBits();}

bool Fixed::operator >= (const Fixed &rhs) const{
	return m_nb >= rhs.getRawBits();}

bool Fixed::operator <= (const Fixed &rhs) const{
	return m_nb <= rhs.getRawBits();}

bool Fixed::operator == (const Fixed &rhs) const{
	return m_nb == rhs.getRawBits();}

bool Fixed::operator != (const Fixed &rhs) const{
	return m_nb != rhs.getRawBits();}

Fixed Fixed::operator + (const Fixed &rhs) const{
	return Fixed(this->toFloat() + rhs.toFloat());}

Fixed Fixed::operator - (const Fixed &rhs) const{
	return Fixed(this->toFloat() - rhs.toFloat());}

Fixed Fixed::operator * (const Fixed &rhs) const{
	return Fixed(this->toFloat() * rhs.toFloat());}

Fixed Fixed::operator / (const Fixed &rhs) const{
	return Fixed(this->toFloat() / rhs.toFloat());}

Fixed& Fixed::operator ++ ( void ){
	++this->m_nb;
	return *this;}

Fixed Fixed::operator ++ ( int ){
	Fixed tmp(*this);
	tmp.m_nb = this->getRawBits();
	m_nb++;
	return tmp;}

Fixed& Fixed::operator -- ( void ){
	--this->m_nb;
	return *this;}

Fixed Fixed::operator -- ( int ){
	Fixed tmp(*this);
	tmp.m_nb = this->getRawBits();
	m_nb--;
	return tmp;}

//  ACCESSORS
int Fixed::getRawBits( void ) const{
	return m_nb;}

// METHODS
void Fixed::setRawBits( int const raw ){
	m_nb = raw;}

float Fixed::toFloat( void ) const{
	return ((float)m_nb / (float)(1 << m_fractBits)); }

int Fixed::toInt( void ) const{
	return getRawBits() >> m_fractBits;}

Fixed& Fixed::min (Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::min (const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::max (Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max (const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

// OTHERS
std::ostream & operator << (std::ostream &out, const Fixed &rhs){
	out << rhs.toFloat();
	return out;}
