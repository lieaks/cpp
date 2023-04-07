#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--------DAVID----------" << std::endl;
	try{
		Bureaucrat david("david", 1);
		std::cout << david;
		while (david.getGrade() < 150)
			david.gradeDecrement();
		std::cout << david;
		while (david.getGrade() > 1)
			david.gradeIncrement();
		std::cout << david;
		david.gradeIncrement();
		std::cout << david;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------GOLIATH----------" << std::endl;
	try{
		Bureaucrat goliath("goliath", 0);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat goliath("goliath", 151);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------COMPARE----------" << std::endl;
	try{
		Bureaucrat david("david", 1);
		Bureaucrat goliath("goliath", 150);
		Bureaucrat dieu(david);

		std::cout << david << goliath << "dieu: " << dieu;
		david = goliath; 
		std::cout << david << goliath << "dieu: " << dieu;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
};