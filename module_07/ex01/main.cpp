#include "iter.hpp"

int main()
{
	int int_array[] = {2, 3, 4, 5};
	double double_array[] = {2.2, 3.3, 4.4, 5.5};
	char char_array[] = {'a', 'b', 'c', 'd'};
	std::string str_array[] = {"david", "ly", "42", "iter"};

	iter(int_array, 4, &print);
	iter(double_array, 4, &print);
	iter(char_array, 4, &print);
	iter(str_array, 4, &print);
	return 0;
}