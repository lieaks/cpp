#include "RobotomyRequestForm.hpp"

/* -----------------CONSTRUCTOR-----------------*/
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), m_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
	*this = src;}

/* -----------------DESTRUCTOR-----------------*/
RobotomyRequestForm::~RobotomyRequestForm() {}

/* -----------------OPERATOR-----------------*/
RobotomyRequestForm & RobotomyRequestForm::operator= (const RobotomyRequestForm &rhs) {
	if (this != &rhs)
	{
		m_target = rhs.m_target;
	}
	return *this;}

/* -----------------METHOD-----------------*/
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	std::cout << (rand() % 2 ? m_target + " has been robotized" : "robotomy failed ") << std::endl;
}