#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : m_name(name) {
	setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &rhs) {
	if (this != &rhs)
	{
		m_name = rhs.m_name; 
		m_grade = rhs.m_grade;
	}
	return *this;
}

void Bureaucrat::setGrade(int grade) {
	if (grade < 1){
		throw GradeTooLowException();
	}
	else if (grade > 150){
		throw GradeTooHighException();
	}
	else
		m_grade = grade;
}

void Bureaucrat::gradeIncrement() {
	setGrade(m_grade - 1);
}

void Bureaucrat::gradeDecrement() {
	setGrade(m_grade + 1);
}

std::string Bureaucrat::getName() const {
	return m_name;
}

int Bureaucrat::getGrade() const {
	return m_grade;
}

std::ostream & operator<< (std::ostream &out, const Bureaucrat &rhs) {
	out << rhs.getName() << ", bureaucrat " << rhs.getGrade() << "." << std::endl;
	return out;
}