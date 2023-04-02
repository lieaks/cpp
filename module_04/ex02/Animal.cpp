#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default Contructor called" << std::endl; }

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl; }

Animal::Animal(const Animal &src) {
	std::cout << "Animal copy Contructor called" << std::endl;
	*this = src; }

Animal & Animal::operator = (const Animal &rhs)
{
	if (this != &rhs)
		m_type = rhs.m_type;
	return *this;}

void Animal::makeSound() const {}

std::string Animal::getType() const {
	return m_type;}
