#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("") {
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << "DiamondTrap default constructor called"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) {
	m_name = name;
	ClapTrap::m_name = name + "_clap_name";
	m_hitPoints = FragTrap::m_hitPoints;
	m_energyPoints = ScavTrap::m_energyPoints;
	m_attackDamage = FragTrap::m_attackDamage;
	std::cout << "DiamondTrap " << m_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) {
	std::cout << " DiamondTrap " << m_name << " copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << m_name << " destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &rhs){
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hitPoints = rhs.m_hitPoints;
		m_energyPoints = rhs.m_energyPoints;
		m_attackDamage = rhs.m_attackDamage;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << m_name << " has a ClapTrap name of " << ClapTrap::m_name << std::endl;
}