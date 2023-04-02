#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap david("David");
	FragTrap goliath("Goliath");
	
	david.attack("Goliath");
	goliath.takeDamage(david.getAttackDamage());
	goliath.highFivesGuys();
	goliath.beRepaired(20);

	return 0;
}