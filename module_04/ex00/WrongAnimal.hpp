#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
	WrongAnimal();	
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal();	
	WrongAnimal & operator = (const WrongAnimal &rhs);

	void makeSound() const;
	std::string getType() const;

	protected:
	std::string m_type;
};

#endif //WRONGANIMAL_HPP