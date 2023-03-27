#include "Sed.hpp"
#include <iostream>
#include <fstream>

Sed::Sed(std::string filename) : m_infile(filename)
{
	m_outfile = filename + ".replace";
}

Sed::~Sed(){}

void Sed::replace(std::string s1, std::string s2)
{
	std::string line;

	std::ifstream infile(m_infile);
	if (not infile)
	{
		std::cerr << "Error infile: " << m_infile << std::endl;
		exit(1);
	}
	std::ofstream outfile(m_outfile);
	if (not outfile)
	{
		std::cerr << "Error outfile: " << m_outfile << std::endl;
		exit(2);
	}
	while (std::getline(infile, line))
	{
		size_t	len_s1 = s1.length();
		if (len_s1)
		{
			for(size_t pos = 0; pos < line.length(); pos++)
			{
				if (not line.compare(pos, len_s1, s1))
				{
					line.erase(pos, len_s1);
					line.insert(pos, s2);
				}
			}
		}
		outfile << line;
		if (not infile.eof())
			outfile << "\n";
	}
}