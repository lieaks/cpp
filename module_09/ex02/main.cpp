#include "PmergeMe.hpp"

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe <positive integer sequence as argument> " << std::endl;
		return 1;
	}
	try {
		PmergeMe pmergeme(ac, av);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}