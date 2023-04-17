#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <fstream>

class Bureaucrat ;

class AForm
{
public:
	AForm(std::string name, const int grade_to_sign, const int grade_to_exec);
	AForm(const AForm &src);
	virtual ~AForm();
	AForm & operator = (const AForm &rhs);

	void beSigned(const Bureaucrat &b);
	virtual void execute(Bureaucrat const & executor) const = 0;

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
	class NotSignedException : public std::exception {
		public:
		virtual const char* what() const throw() {return "Form not signed";}
	};
	class ErrorOpen : public std::exception {
		public:
		virtual const char* what() const throw() {return "File open error";}
	};

private:
	AForm();
	const std::string m_name;
	bool m_signed;
	const int m_grade_to_sign;
	const int m_grade_to_exec;
};

std::ostream& operator << (std::ostream &out, const AForm &rhs);

#endif //AFORM_HPP