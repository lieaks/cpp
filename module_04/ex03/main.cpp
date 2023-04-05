#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob"); 
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    
	Character* he = new Character("he");
	Character* you = new Character(*he);
    src = new MateriaSource();
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    tmp = src->createMateria("ice");
    he->equip(tmp);
    tmp = src->createMateria("ice");
    he->equip(tmp);
    tmp = src->createMateria("cure");
    you->equip(tmp);
    tmp = src->createMateria("cure");
    you->equip(tmp);
    *he = *you;
    he->use(0, *he);
    he->use(1, *he);
    you->use(0, *he);
    you->use(1, *he);

    delete he;
    delete you;
    delete src;

return 0; }