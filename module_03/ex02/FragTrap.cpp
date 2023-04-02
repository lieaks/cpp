#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("") {
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << "FragTrap default constructor called"<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << "FragTrap " << m_name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) {
	std::cout << " FragTrap " << m_name << " copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << m_name << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &rhs){
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hitPoints = rhs.m_hitPoints;
		m_energyPoints = rhs.m_energyPoints;
		m_attackDamage = rhs.m_attackDamage;
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (m_energyPoints > 0)
	{
		m_energyPoints--;
		std::cout << "FragTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << m_name << " runs out of energy!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << m_name << " ask a high five!" << std::endl;
}