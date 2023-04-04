#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria () {}

AMateria::AMateria (std::string const & type) : m_type(type){}

AMateria::~AMateria () {}

AMateria::AMateria (const AMateria &src) {
	*this = src;}

AMateria & AMateria::operator= (const AMateria &rhs){
	if (this != &rhs)
		m_type = rhs.m_type;
	return *this;
}

std::string const & AMateria::getType() const {
	return m_type; }

void AMateria::use(ICharacter& target) {
	std::cout << m_type << "uses on" << target.getName() << std::endl;
}