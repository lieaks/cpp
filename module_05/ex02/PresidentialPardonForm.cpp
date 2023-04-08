#include "PresidentialPardonForm.hpp"

/* -----------------CONSTRUCTOR-----------------*/
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), m_target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
	*this = src;}

/* -----------------DESTRUCTOR-----------------*/
PresidentialPardonForm::~PresidentialPardonForm() {}

/* -----------------OPERATOR-----------------*/
PresidentialPardonForm & PresidentialPardonForm::operator= (const PresidentialPardonForm &rhs) {
	if (this != &rhs)
	{
		m_target = rhs.m_target;
	}
	return *this;}

/* -----------------METHOD-----------------*/
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
