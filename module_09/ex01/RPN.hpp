#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>

class RPN
{
public:
	~RPN();
	static long Convert(std::string str);

private:
	RPN();
	RPN(const RPN &);
	RPN & operator = (const RPN &);
};

bool isoperatorsign(const char c);
long dooperation(long first, long second, char c);

#endif //RPN_HPP