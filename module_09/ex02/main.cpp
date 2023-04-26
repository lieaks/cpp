#include "PmergeMe.hpp"

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe <positive integer sequence as argument> " << std::endl;
		return 1;
	}
	return 0;
}