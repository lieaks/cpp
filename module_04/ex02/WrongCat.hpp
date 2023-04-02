#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
	WrongCat();	
	WrongCat(const WrongCat &src);
	virtual ~WrongCat();	
	WrongCat & operator = (const WrongCat &rhs);
	void makeSound() const;

};

#endif //WRONGCAT_HPP