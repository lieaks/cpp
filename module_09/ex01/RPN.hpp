#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>

class RPN
{
public:
	RPN(const std::string str);
	~RPN();
	long Convert(std::string str);
	class ParseException : public std::exception {
		public:
		virtual const char* what() const throw() {return "Error";}; 
	};

private:
	RPN();
	RPN(const RPN &);
	RPN & operator = (const RPN &);
};

int parsearg(std::string str);
bool isoperatorsign(const char c);
double dooperation(double first, double second, char c);

#endif //RPN_HPP