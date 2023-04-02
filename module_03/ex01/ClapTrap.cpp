#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : m_name(""), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0) {
	std::cout << "ClapTrap default constructor called"<< std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0) {
	std::cout << "ClapTrap " << m_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap " << m_name << " copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << m_name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &rhs){
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hitPoints = rhs.m_hitPoints;
		m_energyPoints = rhs.m_energyPoints;
		m_attackDamage = rhs.m_attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (m_energyPoints > 0)
	{
		m_energyPoints--;
		std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << m_name << " runs out of energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_hitPoints > 0)
	{
		(m_hitPoints - amount < 0) ? m_hitPoints = 0 : m_hitPoints -= amount;
		std::cout << "ClapTrap " << m_name << " takes " << amount << " damage! " << std::endl;
	}
	if (m_hitPoints == 0)
		std::cout << "ClapTrap " << m_name << " is dead! " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints > 0)
	{
		m_energyPoints--;
		std::cout << "ClapTrap " << m_name << " repairs itself for " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << m_name << " runs out of energy!" << std::endl;

}

unsigned int ClapTrap::getAttackDamage() const
{
	return m_attackDamage; 
}