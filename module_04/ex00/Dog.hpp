#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
	Dog();	
	Dog(const Dog &src);
	virtual ~Dog();	
	Dog & operator = (const Dog &rhs);
	void makeSound() const;
};

#endif //DOG_HPP