#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : m_name("") {}

Zombie::Zombie(std::string name) : m_name(name) {}

Zombie::~Zombie()
{
	std::cout << "Destructor: " <<m_name << std::endl;
}

void Zombie::announce( void )
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}