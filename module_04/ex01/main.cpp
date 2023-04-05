#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    Dog* dog = new Dog();
    Dog* dog2 = dog;

    dog->getBrain()->setIdea(0, "I'm a dog");

    std::cout << "idea n0 of dog: " + dog->getBrain()->getIdea(0) << std::endl;
    dog2 = new Dog(*dog);


    std::cout << "idea n0 of dog2: " + dog2->getBrain()->getIdea(0) << std::endl;

    dog->getBrain()->setIdea(1, "I'm a hot-dog");
    *dog2 = *dog;
    std::cout << "idea n1 of dog2: " + dog2->getBrain()->getIdea(1) << std::endl;

    delete dog;
    delete dog2;

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

	Cat *chat1 = new Cat();
	chat1->getBrain()->setIdea(0, "caca");
	Cat *chat2 = new Cat();
	chat2->getBrain()->setIdea(0, "pipi");
	*chat2 = *chat1;
    std::cout << "idea n0 of chat1: " + chat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "idea n0 of chat1: " + chat2->getBrain()->getIdea(0) << std::endl;

	delete chat1;
	delete chat2;
return 0; }
