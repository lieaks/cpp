#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default Contructor called" << std::endl; }

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "WrongAnimal copy Contructor called" << std::endl;
	*this = src; }

WrongAnimal & WrongAnimal::operator = (const WrongAnimal &rhs)
{
	if (this != &rhs)
		m_type = rhs.m_type;
	return *this;}

void WrongAnimal::makeSound() const {}

std::string WrongAnimal::getType() const {
	return m_type;}
