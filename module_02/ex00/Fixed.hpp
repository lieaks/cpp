#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();
	Fixed & operator = (const Fixed &rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	private:
	int	m_nb;
	static const int m_fractBits = 8;
};
#endif //FIXED_HPP
