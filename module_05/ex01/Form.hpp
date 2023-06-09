#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat ;

class Form
{
public:
	Form(std::string name, const int grade_to_sign, const int grade_to_exec);
	Form(const Form &src);
	~Form();
	Form & operator = (const Form &rhs);

	void beSigned(const Bureaucrat &b);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	class GradeTooHighException : public std::exception {
		public:
		virtual const char* what() const throw() {return "Grade too high";}
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw() {return "Grade too low";}
	};

private:
	Form();
	const std::string m_name;
	bool m_signed;
	const int m_grade_to_sign;
	const int m_grade_to_exec;
};

std::ostream& operator << (std::ostream &out, const Form &rhs);

#endif //FORM_HPP