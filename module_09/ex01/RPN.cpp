#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN::~RPN() {}

RPN & RPN::operator = (const RPN &) {return *this;}

long RPN::Convert(std::string str) {
	std::stack<long> stack;
	long tmp = 0, res = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(' || str[i] == ')') 
		{
			std::cerr << "Error" << std::endl;
			exit (1);
		}
		if (isdigit(str[i]))
			stack.push(std::atoi(&str[i]));
		else if (isoperatorsign(str[i]))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				exit (1);
			}
			tmp = stack.top();
			stack.pop();
			res = dooperation(stack.top(), tmp, str[i]);
			stack.pop();
			stack.push(res);
		}
	}
	return res;
}

bool isoperatorsign(const char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

long dooperation(long first, long second, char c)
{
	if (c == '+')
		return first + second;
	else if (c == '-')
		return first - second;
	else if (c == '/')
		return first / second;
	else 
		return first * second;
}