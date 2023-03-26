#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"

class HumanA
{
	public:
	HumanA();
	HumanA(std::string str, Weapon& weapon);
	~HumanA();
	void attack();

	private:
	std::string m_name;
	Weapon &m_weapon;
};

#endif //HUMAN_A