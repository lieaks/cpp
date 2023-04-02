#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
	Cat();	
	Cat(const Cat &src);
	virtual ~Cat();	
	Cat & operator = (const Cat &rhs);
	void makeSound() const;

};

#endif //CAT_HPP