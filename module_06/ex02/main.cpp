#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base * generate(void) {
	int r = rand() % 3;
	if (r == 0){
		std::cout << "Creating A" << std::endl;	
		return (new A);
	}
	else if (r == 1){
		std::cout << "Creating B" << std::endl;	
		return (new B);
	}
	else
	{
		std::cout << "Creating C" << std::endl;	
		return (new C);
	}
};

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try{
		identify(&p);
	}
	catch (const std::exception &e){
	}
}

int main()
{
	Base *r1 = generate();
	Base *r2 = generate();
	Base *r3 = generate();

	std::cout << "r1:" << std::endl;
	identify(r1);
	identify(*r1);
	std::cout << std::endl << "r2:" << std::endl;
	identify(r2);
	identify(*r2);
	std::cout << std::endl << "r3:" << std::endl;
	identify(r3);
	identify(*r3);

	delete r1;
	delete r2;
	delete r3;
}