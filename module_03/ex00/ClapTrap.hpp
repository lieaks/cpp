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

	std::string getName() const;
	unsigned int getAttackDamage() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;

	private:
	ClapTrap();
	std::string m_name;
	unsigned int m_hitPoints;
	unsigned int m_energyPoints;
	unsigned int m_attackDamage;
};

#endif