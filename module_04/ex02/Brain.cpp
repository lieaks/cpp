#include "Brain.hpp"
#include <iostream>

Brain::Brain () {
	std::cout << "Brain default Contructor called" << std::endl;}

Brain::Brain (const Brain &src) {
	std::cout << "Brain copy Contructor called" << std::endl;
	*this = src;}

Brain::~Brain () {
	std::cout << "Brain Destructor called" << std::endl;}

Brain & Brain::operator= (const Brain &rhs){
	if (this != &rhs)
	{
		for(int i = 0; i < 100; i++)
			m_ideas[i] = rhs.m_ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int idx) const{
	return m_ideas[idx];
}

void Brain::setIdea(int idx, std::string str){
	m_ideas[idx] = str;
}