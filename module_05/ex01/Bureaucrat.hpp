#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	Bureaucrat();
	const std::string m_name;
	int m_grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();
	Bureaucrat& operator= (const Bureaucrat &src);
	
	void setGrade(int grade);
	void gradeIncrement();
	void gradeDecrement();
	void signForm(Form &form) const;

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