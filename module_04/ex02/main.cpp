#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	delete j;//should not create a leak delete i;
	delete i;

	Animal *animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 4 / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];
return 0; }