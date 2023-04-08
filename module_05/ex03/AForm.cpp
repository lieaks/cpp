#include "AForm.hpp"

/* -----------------CONSTRUCTOR-----------------*/
AForm::AForm() : m_name("default form"), m_signed(false), m_grade_to_sign(150), m_grade_to_exec(150) {}

AForm::AForm(std::string name, const int grade_to_sign, const int grade_to_exec) : m_name(name), m_signed(false), m_grade_to_sign(grade_to_sign), m_grade_to_exec(grade_to_exec) {
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw AForm::GradeTooLowException();}

AForm::AForm(const AForm &src) : m_name(src.m_name), m_signed(src.m_signed), m_grade_to_sign(src.m_grade_to_sign), m_grade_to_exec(src.m_grade_to_exec) {
	*this = src;}

/* -----------------DESTRUCTOR-----------------*/
AForm::~AForm() {}

/* -----------------OPERATOR-----------------*/
AForm & AForm::operator= (const AForm &rhs) {
	if (this != &rhs)
		m_signed = rhs.m_signed;
	return *this;}

/* -----------------METHOD-----------------*/
void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > m_grade_to_sign)
		throw AForm::GradeTooLowException();
	m_signed = true;}

/* -----------------GETTER-----------------*/
std::string AForm::getName() const {
	return m_name;}

bool AForm::getSigned() const{
	return m_signed;}

int AForm::getGradeToSign() const{
	return m_grade_to_sign;}

int AForm::getGradeToExec() const{
	return m_grade_to_exec;}

/* -----------------OTHER-----------------*/
std::ostream& operator << (std::ostream &out, const AForm &rhs){
	out << rhs.getName() << (rhs.getSigned() ? " is signed." : " is not signed.") << std::endl
		<< "Grade " << rhs.getGradeToSign() << " required to sign " << rhs.getName() << std::endl
		<< "Grade " << rhs.getGradeToExec() << " required to execute " << rhs.getName() << std::endl;
	return out;}