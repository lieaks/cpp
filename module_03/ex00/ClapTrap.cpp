#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap &src) {

}

ClapTrap::~ClapTrap() {}

ClapTrap& ClapTrap::operator = (const ClapTrap &rhs){
	if (this != &rhs)
	{
		m_name(rhs.m_name);
		m_hitPoints(rhs.m_hitPoints);
		m_energyPoints(rhs.m_energyPoints);
		m_attackDamage(rhs.m_attackDamage);
	}
	
}

void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);