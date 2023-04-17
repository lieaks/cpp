#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>

class Converter
{
public:
	~Converter();

	static void convert(std::string str);

	static bool isChar(std::string str);
	static bool isInt(std::string str);
	static bool isFloat(std::string str);
	static bool isDouble(std::string str);
	static bool isLitteral(std::string str);

	static void printChar(char c);
	static void printInt(long n);
	static void printFloat(float f);
	static void printDouble(double d);

private:
	Converter();
	Converter(const Converter &);
	Converter &operator=(const Converter &);
};

#endif //CONVERTER_HPP