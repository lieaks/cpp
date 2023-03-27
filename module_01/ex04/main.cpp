#include <iostream>
#include "Sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./sedreplace <filename> <string_to_replace> <replacement string>" << std::endl;
		return 1;
	}
	std::string s1(av[2]), s2(av[3]);
	Sed sed(av[1]);
	sed.replace(av[2], av[3]);
	return 0;
}