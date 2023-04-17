#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RNP <input>" << std::endl;
		return 1;
	}
	std::cout << RPN::Convert(av[1]) << std::endl;
	return 0;
}