#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();

	ClapTrap & operator = (const ClapTrap &rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	private:
	std::string m_name;
	int m_hitPoints;
	int m_energyPoints;
	int m_attackDamage;
};

#endif