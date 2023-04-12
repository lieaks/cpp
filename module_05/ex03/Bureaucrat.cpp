#include "Bureaucrat.hpp"

/* -----------------CONSTRUCTOR-----------------*/
Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name) {
	setGrade(grade);}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : m_name(src.m_name) {
	*this = src;}

/* -----------------DESTRUCTOR-----------------*/
Bureaucrat::~Bureaucrat() {}

/* -----------------OPERATOR-----------------*/
Bureaucrat &Bureaucrat::operator = (const Bureaucrat &rhs) {
	if (this != &rhs)
	{
		m_grade = rhs.m_grade;
	}
	return *this;}

/* -----------------SETTER-----------------*/
void Bureaucrat::setGrade(int grade) {
	if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
	else
		m_grade = grade;}

/* -----------------METHOD-----------------*/
void Bureaucrat::gradeIncrement() {
	setGrade(m_grade - 1);}

void Bureaucrat::gradeDecrement() {
	setGrade(m_grade + 1);}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << std::endl; }
	catch (const std::exception &e){
		std::cout << m_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl; } };

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << m_name << " executed " << form.getName() << std::endl;}
	catch (std::exception const &e){
		std::cout << m_name << " can't execute " << form.getName() << ": " << e.what() << std::endl;} };

/* -----------------GETTER-----------------*/
std::string Bureaucrat::getName() const {
	return m_name;}

int Bureaucrat::getGrade() const {
	return m_grade;}

/* -----------------OTHER-----------------*/
std::ostream & operator<< (std::ostream &out, const Bureaucrat &rhs) {
	out << rhs.getName() << ", bureaucrat " << rhs.getGrade() << "." << std::endl;
	return out;}