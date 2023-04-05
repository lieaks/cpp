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
	std::string getIdea(int idx) const;
	void setIdea(int idx, std::string str);

	private:
	std::string m_ideas[100];
};

#endif //BRAIN_HPP