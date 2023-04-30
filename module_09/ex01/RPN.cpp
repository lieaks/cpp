#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string str) {

	std::cout << Convert(str) << std::endl; 
}

RPN::RPN(const RPN &) {}

RPN::~RPN() {}

RPN & RPN::operator = (const RPN &) {return *this;}

double RPN::Convert(std::string str) {
	std::stack<double> stack;
	double tmp = 0;
	double res = 0;
	int single = 0;
	char digit;

	single = parsearg(str);
	if (single == 1)
		throw ParseException();
	for (int i = 0; str[i]; i++)
	{
		if (isdigit(str[i]))
		{
			digit = str[i];
			stack.push(atoi(&digit));
			if (single == 2)
				return stack.top();
		}
		else if (isoperatorsign(str[i]))
		{
			if (stack.size() < 2)
			{
				throw ParseException();
			}
			tmp = stack.top();
			if (tmp == 0 && str[i] == '/')
				throw ParseException();
			stack.pop();
			res = dooperation(stack.top(), tmp, str[i]);
			stack.pop();
			stack.push(res);
		}
	}
	return res;
}

int parsearg(std::string str)
{
	int nb_digit = 0;
	int nb_opesign = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isoperatorsign(str[i]) && !isdigit(str[i]) && str[i] != ' ')
			return 1;
		if (isdigit(str[i]))
			nb_digit++;
		if (isoperatorsign(str[i]))
			nb_opesign++;
	}
	if (nb_opesign == 0 && nb_digit == 1)
		return 2;
	if (nb_opesign == nb_digit - 1)
		return 0;
	return 1;
}

bool isoperatorsign(const char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

double dooperation(double first, double second, char c)
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