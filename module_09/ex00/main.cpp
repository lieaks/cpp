#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc <input file>" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc(av[1]);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	// data = btc.getData();
	// for (it = data.begin(); it != data.end(); it++)
	// 	std::cout << it->first << "," << it->second << std::endl;
	return 0;
}