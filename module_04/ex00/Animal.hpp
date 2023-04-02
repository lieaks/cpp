#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
	Animal();	
	Animal(const Animal &src);
	virtual ~Animal();	
	Animal & operator = (const Animal &rhs);

	virtual void makeSound() const;
	std::string getType() const;

	protected:
	std::string m_type;
};

#endif //ANIMAL_HPP