#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap david("David");
	ClapTrap goliath("Goliath");
	
	david.attack("Goliath");
	goliath.takeDamage(david.getAttackDamage());
	goliath.beRepaired(20);

	return 0;
}