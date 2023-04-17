#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(const Converter &) {}

Converter::~Converter() {}

Converter & Converter::operator= (const Converter &) {return *this;}

bool Converter::isChar(std::string str) {
	return (str.length() == 1 && std::isprint(str[0]) && std::isalpha(str[0])); };

bool Converter::isInt(std::string str) {
	char *endptr = NULL;

	std::strtol(str.c_str(), &endptr, 10);
	return (endptr == &str[0] + str.length()); };

bool Converter::isFloat(std::string str) {
	char *endptr = NULL;

	std::strtof(str.c_str(), &endptr);
	return (*endptr == 'f' && (endptr == &str[0] + str.length()) + 1); };

bool Converter::isDouble(std::string str) {
	char *endptr = NULL;

	std::strtod(str.c_str(), &endptr);
	return (endptr == &str[0] + str.length()); };

void Converter::convert(std::string str) {
	if (isChar(str))
		printChar(str[0]);
	else if (isInt(str))
		printInt(std::atol(str.c_str()));
	else if (isFloat(str))
		printFloat(std::strtof(str.c_str(), NULL));
	else if (isDouble(str))
		printDouble(std::strtod(str.c_str(), NULL));
	else
		std::cout << "Unknow type" << std::endl; }

void Converter::printChar(char c){
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;}

void Converter::printInt(long n){
	char c = static_cast<char>(n);
	if (c < CHAR_MIN || c > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (not std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;}

void Converter::printFloat(float f) {
	char c = static_cast<char>(f);
	if (f < CHAR_MIN || f > CHAR_MAX || std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible" << std::endl;
	else if (not std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX) || std::isnan(f) || std::isinf(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;}

void Converter::printDouble(double d) {
	char c = static_cast<char>(d);
	if (d < CHAR_MIN || d > CHAR_MAX || std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible" << std::endl;
	else if (not std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;}