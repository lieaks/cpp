#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("") {
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	std::cout << "ScavTrap default constructor called"<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	std::cout << "ScavTrap " << m_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) {
	std::cout << " ScavTrap " << m_name << " copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << m_name << " destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &rhs){
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hitPoints = rhs.m_hitPoints;
		m_energyPoints = rhs.m_energyPoints;
		m_attackDamage = rhs.m_attackDamage;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (m_energyPoints > 0)
	{
		m_energyPoints--;
		std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << m_name << " runs out of energy!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << m_name << " is in Gate keeper mode!" << std::endl;
}