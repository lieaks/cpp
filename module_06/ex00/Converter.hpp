#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITTERAL,
	NONE
};

class Converter
{
public:
	Converter(std::string str);
	Converter(const Converter &);
	~Converter();
	Converter &operator=(const Converter &);

	void getType();
	bool isChar();
	bool isInt();
	bool isFloat();
	bool isDouble();
	bool isLitteral();

	void convert();
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

private:
	Converter();
	std::string m_str;
	e_type m_type;
};

#endif //CONVERTER_HPP