#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> tab(5, 0);
	for (unsigned int i(0); i < tab.size(); i++)
		tab[i] = i;
	easyfind(tab, 10);
	easyfind(tab, 1);

	return 0;}