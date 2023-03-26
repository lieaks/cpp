#ifndef SED_HPP
#define SED_HPP

#include <string>

class Sed
{
	public:
	Sed(std::string filename);
	~Sed();
	void replace(std::string s1, std::string s2);

	private:
	std::string m_infile;
	std::string m_outfile;
};

#endif //SED_HPP