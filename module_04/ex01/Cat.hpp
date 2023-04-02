#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

class Cat : public Animal
{
	public:
	Cat();	
	Cat(const Cat &src);
	virtual ~Cat();	
	Cat & operator = (const Cat &rhs);
	void makeSound() const;

	private:
	Brain *m_brain;
};

#endif //CAT_HPP