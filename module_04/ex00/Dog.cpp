#include "Dog.hpp"

Dog::Dog() {
	m_type = "Dog";
	std::cout << "Dog default Contructor called" << std::endl; }

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl; }

Dog::Dog(const Dog &src) {
	std::cout << "Dog copy Contructor called" << std::endl;
	*this = src; }

Dog & Dog::operator = (const Dog &rhs) {
	if (this != &rhs)
		m_type = rhs.m_type;
	return *this; }

void Dog::makeSound() const {
	std::cout << "Ouaf" << std::endl; }