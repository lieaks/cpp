#include "Form.hpp"

Form::Form() : m_name("default form"), m_grade_to_sign(150), m_grade_to_exec(150) {}

Form::Form(std::string name, const int grade_to_sign, const int grade_to_exec) : m_name(name), m_grade_to_sign(grade_to_sign), m_grade_to_exec(grade_to_exec) {
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : m_name(src.m_name), m_grade_to_sign(src.m_grade_to_sign), m_grade_to_exec(src.m_grade_to_exec) {
	*this = src;
}

Form::~Form() {}

Form & Form::operator= (const Form &rhs) {
	if (this != &rhs)
		m_signed = rhs.m_signed;
}