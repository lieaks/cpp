#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap david("David");
	ClapTrap goliath("Goliath");
	
	david.attack("Goliath");
	goliath.takeDamage(david.getAttackDamage());
	david.guardGate();
	goliath.beRepaired(20);

	return 0;
}