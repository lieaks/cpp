#ifndef DIAMONDTRAP_HPP 
#define DIAMONDTRAP_HPP 

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
	public :
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &src);
	~DiamondTrap();

	DiamondTrap & operator = (const DiamondTrap &rhs);

	void attack(const std::string& target);
	void whoAmI();

	private:
	std::string m_name;
};

#endif //DiamondTrap_HPP