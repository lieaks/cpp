#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	try{
		std::cout << "--------ShrubberyCreationForm----------" << std::endl;
		Bureaucrat	david("david", 1);
		Bureaucrat	goliath("goliath", 150);
		ShrubberyCreationForm f1("tree");
		std::cout << david << goliath << f1 << std::endl;

		david.executeForm(f1);
		goliath.executeForm(f1);
		goliath.signForm(f1);
		david.signForm(f1);
		goliath.executeForm(f1);
		david.executeForm(f1);
		std::cout << f1 << std::endl;

		std::cout << "--------RobotomyRequestForm---------" << std::endl;
		RobotomyRequestForm f2("frank");
		david.executeForm(f2);
		goliath.executeForm(f2);
		goliath.signForm(f2);
		david.signForm(f2);
		goliath.executeForm(f2);
		david.executeForm(f2);
		david.executeForm(f2);
		david.executeForm(f2);
		david.executeForm(f2);

		std::cout << std::endl << "--------PresidentialPardonForm--------" << std::endl;
		PresidentialPardonForm f3("eden");
		david.executeForm(f3);
		goliath.executeForm(f3);
		goliath.signForm(f3);
		david.signForm(f3);
		goliath.executeForm(f3);
		david.executeForm(f3);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
};