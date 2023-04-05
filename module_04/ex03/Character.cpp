#include "Character.hpp"

Character::Character() {};

Character::Character(std::string name) : m_name(name) {
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i])
			delete m_inventory[i];
	}
}

Character & Character::operator= (const Character &rhs) {
	if (this != &rhs)
	{
		m_name = rhs.getName();
		for (int i = 0; i < 4; i++)
			m_inventory[i] = rhs.m_inventory[i];
	}
	return *this;
}

std::string const & Character::getName() const {
	return m_name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] == NULL)
		{
			m_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx){
	if (m_inventory[idx])
		m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (m_inventory[idx])
		m_inventory[idx]->use(target);
}