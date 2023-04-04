#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter
{
public:	
	Character(std::string name);
	Character(const Character &src);
	virtual ~Character();
	Character & operator=(const Character &rhs);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:
	Character();
	std::string m_name;
	AMateria* m_inventory[4];
};

#endif //CHARACTER_HPP