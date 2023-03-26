#include <iostream>
#include "Zombie.hpp"

int	main()
{
	Zombie stack_zombie("stack_zombie");
	Zombie *heap_zombie = newZombie("heap_zombie");

	stack_zombie.announce();
	heap_zombie->announce();
	std::cout << std::endl;
	randomChump("rand_chump");
	std::cout << std::endl;
	delete heap_zombie;

	return 0;
}