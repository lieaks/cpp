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
	bool operator > (const Fixed &rhs) const;
	bool operator < (const Fixed &rhs) const;
	bool operator >= (const Fixed &rhs) const;
	bool operator <= (const Fixed &rhs) const;
	bool operator == (const Fixed &rhs) const;
	bool operator != (const Fixed &rhs) const;
	Fixed operator + (const Fixed &rhs) const;
	Fixed operator - (const Fixed &rhs) const;
	Fixed operator * (const Fixed &rhs) const;
	Fixed operator / (const Fixed &rhs) const;
	Fixed& operator ++ ( void );
	Fixed operator ++ ( int );
	Fixed& operator -- ( void );
	Fixed operator -- ( int );

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;	

	static Fixed& min (Fixed &n1, Fixed &n2);
	const static Fixed& min (const Fixed &n1, const Fixed &n2);
	static Fixed& max (Fixed &n1, Fixed &n2);
	const static Fixed& max (const Fixed &n1, const Fixed &n2);

	private:
	int	m_nb;
	static const int m_fractBits = 8;
};

std::ostream & operator << (std::ostream &out, const Fixed &rhs);

#endif //FIXED_HPP
