#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	Bureaucrat();
	std::string m_name;
	int m_grade;

public:
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();
	Bureaucrat& operator= (const Bureaucrat &src);
	
	void setGrade(int grade);
	void gradeIncrement();
	void gradeDecrement();

	std::string getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception {
		public:
		virtual const char* what() const throw() {return "Grade too high";}
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw() {return "Grade too low";}
	};
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &src);

#endif //BUREAUCRAT_HPP