#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

int main()
{
	int int_array[] = {2, 3, 4, 5};
	double double_array[] = {2.2, 3.3, 4.4, 5.5};
	char char_array[] = {'a', 'b', 'c', 'd'};
	std::string str_array[] = {"david", "ly", "42", "iter"};

	iter(int_array, 4, print<int>);
	iter(double_array, 4, print<double>);
	iter(char_array, 4, print<char>);
	iter(str_array, 4, print<std::string>);

	std::cout << "------------------NEW TEST-------------------" << std::endl;

	int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];

  	iter( tab, 5, print<int> );
  	iter( tab2, 5, print<Awesome> );

	return 0;
}