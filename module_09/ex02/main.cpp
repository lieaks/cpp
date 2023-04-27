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
	// int tab[] = {5, 2, 3, 1, 4, 7, 6};
	// std::vector<int> vec;
	// vec.assign(tab, tab + 7);
	// std::cout << vec[2] << std::endl;
	// sort(vec);
	return 0;
}