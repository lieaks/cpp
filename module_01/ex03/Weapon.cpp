#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string str) : m_type(str) {}

const std::string& Weapon::getType()
{
	return m_type;
}

void Weapon::setType(std::string str)
{
	m_type = str;
}