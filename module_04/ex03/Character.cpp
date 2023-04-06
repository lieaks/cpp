#include "Character.hpp"

Character::Character() {};

Character::Character(std::string name) : m_name(name) {
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] != NULL)
			delete m_inventory[i];
		m_inventory[i] = NULL;
	}
}

Character::Character(const Character &src) {
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
	*this = src;
}

Character & Character::operator= (const Character &rhs) {
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		for (int i = 0; i < 4; i++)
		{
			if (m_inventory[i])
				delete (m_inventory[i]);
			if (rhs.m_inventory[i])
				m_inventory[i] = rhs.m_inventory[i]->clone();
		}
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
	if (m_inventory[idx % 4])
		m_inventory[idx % 4] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (m_inventory[idx % 4])
		m_inventory[idx % 4]->use(target);
}