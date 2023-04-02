#include "Cat.hpp"

Cat::Cat() {
	m_type = "Cat";
	std::cout << "Cat default Contructor called" << std::endl; }

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl; }

Cat::Cat(const Cat &src) {
	std::cout << "Cat copy Contructor called" << std::endl;
	*this = src; }

Cat & Cat::operator = (const Cat &rhs) {
	if (this != &rhs)
		m_type = rhs.m_type;
	return *this; }

void Cat::makeSound() const {
	std::cout << "Miaou" << std::endl; }