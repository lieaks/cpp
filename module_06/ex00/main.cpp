#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert <input>" << std::endl;
		return 1;
	}
	Converter converter(av[1]);
	converter.convert();
	return 0;
}