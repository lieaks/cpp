#include "Dog.hpp"

Dog::Dog() {
	m_type = "Dog";
	m_brain = new Brain();
	std::cout << "Dog default Contructor called" << std::endl; }

Dog::~Dog() {
	delete m_brain;
	std::cout << "Dog Destructor called" << std::endl; }

Dog::Dog(const Dog &src) {
	std::cout << "Dog copy Contructor called" << std::endl;
	*this = src; }

Dog & Dog::operator = (const Dog &rhs) {
	if (this != &rhs)
	{
		m_type = rhs.m_type;
		if (m_brain != NULL)
			delete(m_brain);
		m_brain = new Brain(*rhs.m_brain);
	}
	return *this; }

void Dog::makeSound() const {
	std::cout << "Ouaf" << std::endl; }