#include "Cat.hpp"

Cat::Cat() {
	m_type = "Cat";
	m_brain = new Brain();
	std::cout << "Cat default Contructor called" << std::endl; }

Cat::~Cat() {
	delete m_brain;
	std::cout << "Cat Destructor called" << std::endl; }

Cat::Cat(const Cat &src) {
	std::cout << "Cat copy Contructor called" << std::endl;
	m_brain = NULL;
	*this = src; }

Cat & Cat::operator = (const Cat &rhs) {
	if (this != &rhs)
	{
		m_type = rhs.m_type;
		if (m_brain != NULL)
			delete(m_brain);
		m_brain = new Brain(*rhs.m_brain);
	}
	return *this; }

void Cat::makeSound() const {
	std::cout << "Miaou" << std::endl; }

Brain* Cat::getBrain() const{
	return m_brain;
}