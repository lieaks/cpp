#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RNP <input>" << std::endl;
		return 1;
	}
	try {
		RPN calculator(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl ;
	}
	return 0;
}