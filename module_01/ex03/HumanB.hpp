#ifndef HUMAN_B
#define HUMAN_B

#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB();
	HumanB(std::string str);
	~HumanB();
	const void attack();
	void setWeapon(Weapon &weapon);

	private:
	std::string m_name;
	Weapon *m_weapon;
};

#endif //HUMAN_B