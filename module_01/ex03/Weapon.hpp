#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	public:
	Weapon(std::string str);
	const std::string& getType();
	void setType(std::string str);

	private:
	std::string m_type;
};

#endif //WEAPON_HPP