#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

class Bureaucrat
{
private:
	Bureaucrat();
	std::string getName();
	unsigned int getGrade();

public:
	Bureaucrat(std::string name, unsigned int m_grade);
	~Bureaucrat();
	Bureaucrat& operator= (const Bureaucrat &src);
	Bureaucrat& operator+ (const Bureaucrat &src);
	Bureaucrat& operator- (const Bureaucrat &src);
	const std::string m_name;
	unsigned int m_grade;
};

ostream& operator << (ostream &out, Bureaucrat &src);

#endif //BUREAUCRAT_HPP