#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	virtual void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;

private:
	ShrubberyCreationForm();
	std::string m_target;
};

#endif //SHRUBBERYCREATIONFORM_HPP