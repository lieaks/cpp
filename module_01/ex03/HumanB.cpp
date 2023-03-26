#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL) {}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon)
{
	m_weapon = &weapon;
}

const void HumanB::attack()
{
	std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}