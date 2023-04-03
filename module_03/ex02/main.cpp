#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap david("David");
	FragTrap goliath("Goliath");
	
	std::cout << "Name: " << david.getName() << std::endl;
	std::cout << "Hit points: " << david.getHitPoints() << std::endl;
	std::cout << "Energy points: " << david.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << david.getAttackDamage() << std::endl;
	david.attack("Goliath");
	goliath.attack("David");
	goliath.highFivesGuys();

	std::cout << "Name: " << goliath.getName() << std::endl;
	std::cout << "Hit points: " << goliath.getHitPoints() << std::endl;
	std::cout << "Energy points: " << goliath.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << goliath.getAttackDamage() << std::endl;
	return 0;
}