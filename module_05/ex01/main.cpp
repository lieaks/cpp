#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	std::cout << "--------DAVID----------" << std::endl;
	try{
		Bureaucrat	david("david", 50);
		Form		f1("f1", 70, 70);
		Form		f2("f2", 20, 20);
		std::cout << david << f1 << f2;
		david.signForm(f1);
		david.signForm(f2);
		std::cout << f1 << f2;
		f1 = f2;
		std::cout << f1 << f2;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
};