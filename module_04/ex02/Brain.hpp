#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	public:
	Brain();
	Brain(const Brain &src);
	~Brain();
	Brain & operator = (const Brain &rhs);

	private:
	std::string m_ideas[100];
};

#endif //BRAIN_HPP