#include "Cure.hpp"
#include <iostream>

Cure::Cure () : AMateria("cure") {}

Cure::Cure (const Cure &src) {
	*this = src;}

Cure::~Cure ()  {}

Cure & Cure::operator= (const Cure &rhs){
	if (this != &rhs)
	{
		m_type = rhs.m_type;
	}
	return *this;}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}