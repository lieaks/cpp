#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(std::string str) : m_str(str) {}

Converter::Converter(const Converter &src) : m_str(src.m_str) {}

Converter::~Converter() {}

Converter & Converter::operator= (const Converter &rhs) {
	if (this != &rhs){
		m_str = rhs.m_str;
	}
	
	return *this;}

void Converter::getType () {
	e_type type[] = {CHAR, INT, FLOAT, DOUBLE};
	bool (Converter::*func[])() = {&Converter::isChar, &Converter::isInt, &Converter::isFloat, &Converter::isDouble};
	for (int i = 0; i < 4; i++)
	{
		if ((this->*func[i])() == true){
			m_type = type[i];
			break ;} 
		if (i == 3)
			m_type = NONE;
	};}

bool Converter::isChar() {
	return (m_str.length() == 1 && std::isprint(m_str[0]) && std::isalpha(m_str[0])); };

bool Converter::isInt() {
	char *endptr = NULL;

	std::strtol(m_str.c_str(), &endptr, 10);
	return (endptr == &m_str[0] + m_str.length()); };

bool Converter::isFloat() {
	char *endptr = NULL;

	std::strtof(m_str.c_str(), &endptr);
	return (*endptr == 'f' && (endptr == &m_str[0] + m_str.length()) + 1); };

bool Converter::isDouble() {
	char *endptr = NULL;

	std::strtod(m_str.c_str(), &endptr);
	return (endptr == &m_str[0] + m_str.length()); };

void Converter::convert() {
	e_type type[] = {CHAR, INT, FLOAT, DOUBLE};
	void (Converter::*func[])() = {&Converter::printChar, &Converter::printInt, &Converter::printFloat, &Converter::printDouble};

	getType();
	for (int i = 0; i < 4; i++)
	{
		if (m_type == type[i])
		{
			(this->*func[i])();
			break ;
		}
		if (i == 3)
			std::cout << "Unknow type" << std::endl;
	}
}

void Converter::printChar(){
	char c = m_str[0];

	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;}

void Converter::printInt(){
	long n = std::atol(m_str.c_str());

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

void Converter::printFloat() {
	float f = std::strtof(m_str.c_str(), NULL);

	char c = static_cast<char>(f);
	if (f < CHAR_MIN || f > CHAR_MAX || std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible" << std::endl;
	else if (not std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (f < INT_MIN || f > INT_MAX || std::isnan(f) || std::isinf(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;}

void Converter::printDouble() {
	double d = std::strtod(m_str.c_str(), NULL);

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