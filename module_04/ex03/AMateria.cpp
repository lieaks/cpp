#include "AMateria.hpp"

AMateria::AMateria () {}

AMateria::AMateria (std::string const & type) : m_type(type){}

AMateria::~AMateria () {}

AMateria::AMateria (const AMateria &src) {
	*this = src;}

AMateria & AMateria::operator= (const AMateria &rhs){
	if (this != &rhs)
		m_type = rhs.m_type;}

std::string const & AMateria::getType() const {
	return m_type; }