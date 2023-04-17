#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();
	RobotomyRequestForm & operator=(const RobotomyRequestForm &rhs);
	virtual void execute(Bureaucrat const & executor) const;

private:
	RobotomyRequestForm();
	std::string m_target;
};

#endif //ROBOTOMYREQUESTFORM_HPP