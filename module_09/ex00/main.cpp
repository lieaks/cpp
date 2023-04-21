#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc <input file>" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	std::vector<Data> data;
	std::vector<Data>::iterator it;
	try{
		btc.setData("data.csv");
		btc.exchange(av[1]);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	// data = btc.getData();
	// for (it = data.begin(); it != data.end(); it++)
		// std::cout << it->time.tm_year << "-" << it->time.tm_mon << "-" << it->time.tm_mday << "," << it->price << std::endl;
	return 0;
}