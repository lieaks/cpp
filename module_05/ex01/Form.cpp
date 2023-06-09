#include "Form.hpp"

/* -----------------CONSTRUCTOR-----------------*/
Form::Form() : m_name("default form"), m_signed(false), m_grade_to_sign(150), m_grade_to_exec(150) {}

Form::Form(std::string name, const int grade_to_sign, const int grade_to_exec) : m_name(name), m_signed(false), m_grade_to_sign(grade_to_sign), m_grade_to_exec(grade_to_exec) {
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw Form::GradeTooLowException();}

Form::Form(const Form &src) : m_name(src.m_name), m_signed(src.m_signed), m_grade_to_sign(src.m_grade_to_sign), m_grade_to_exec(src.m_grade_to_exec) {
	*this = src;}

/* -----------------DESTRUCTOR-----------------*/
Form::~Form() {}

/* -----------------OPERATOR-----------------*/
Form & Form::operator= (const Form &rhs) {
	if (this != &rhs)
		m_signed = rhs.m_signed;
	return *this;}

/* -----------------METHOD-----------------*/
void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > m_grade_to_sign)
		throw Form::GradeTooLowException();
	m_signed = true;}

/* -----------------GETTER-----------------*/
std::string Form::getName() const {
	return m_name;}

bool Form::getSigned() const{
	return m_signed;}

int Form::getGradeToSign() const{
	return m_grade_to_sign;}

int Form::getGradeToExec() const{
	return m_grade_to_exec;}

/* -----------------OTHER-----------------*/
std::ostream& operator << (std::ostream &out, const Form &rhs){
	out << rhs.getName() << (rhs.getSigned() ? " is signed." : " is not signed.") << std::endl
		<< "Grade " << rhs.getGradeToSign() << " required to sign " << rhs.getName() << std::endl
		<< "Grade " << rhs.getGradeToExec() << " required to execute " << rhs.getName() << std::endl;
	return out;}