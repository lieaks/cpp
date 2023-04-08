#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &) {}

Intern::~Intern() {}

Intern & Intern::operator= (const Intern &) { return *this;}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
	std::string names[] = {
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"};
	AForm		*forms[] = {
		new ShrubberyCreationForm(target), 
		new RobotomyRequestForm(target), 
		new PresidentialPardonForm(target)};
	AForm		*result = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			result = forms[i];
		}
		else
			delete forms[i];
	}
	if (not result)
		std::cout << "Intern cannot create " << name << " form" << std::endl;
	return result;
}