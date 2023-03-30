#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
	Fixed();
	Fixed(const int nb);
	Fixed(const double nb);
	Fixed(const Fixed &src);
	~Fixed();
	Fixed & operator = (const Fixed &rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;	

	private:
	int	m_nb;
	static const int m_fractBits = 8;
};

std::ostream & operator << (std::ostream &out, const Fixed &rhs);

#endif //FIXED_HPP
