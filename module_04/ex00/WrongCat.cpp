#include "WrongCat.hpp"

WrongCat::WrongCat() {
	m_type = "WrongCat";
	std::cout << "WrongCat default Contructor called" << std::endl; }

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat &src) {
	std::cout << "WrongCat copy Contructor called" << std::endl;
	*this = src; }

WrongCat & WrongCat::operator = (const WrongCat &rhs) {
	if (this != &rhs)
		m_type = rhs.m_type;
	return *this; }

void WrongCat::makeSound() const {
	std::cout << "Miaou" << std::endl; }