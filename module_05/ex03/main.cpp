#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try{
		Bureaucrat david("david", 1);
		Intern  someRandomIntern;
    	AForm*   rrf;

    	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		david.signForm(*rrf);
		delete rrf;
    	rrf = someRandomIntern.makeForm(" request", "Bender");
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
};