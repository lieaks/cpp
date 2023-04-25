#include "Span.hpp"

/* -----------------CONSTRUCTOR-----------------*/
Span::Span() {};

Span::Span(unsigned int n) : m_vector(0), m_size(n) {};

Span::Span(const Span &src) {
	*this = src;};

/* -----------------DESTRUCTOR-----------------*/
Span::~Span() {};

/* -----------------OPERATOR-----------------*/
Span& Span::operator= (const Span &rhs) {
	if (this != &rhs)
	{
		m_vector = rhs.m_vector;
		m_size = rhs.m_size;
	}
	return *this; };

/* -----------------METHOD-----------------*/
void Span::addNumber(int value) {
	if (m_vector.size() >= m_size)
		throw std::out_of_range("Error: Out of range");
	m_vector.push_back(value); };

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (m_vector.size() >= m_size)
		throw std::out_of_range("Error: Out of range");
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		addNumber(*it); };
	}

int Span::shortestSpan() {
	if (m_vector.size() < 2)
		throw std::logic_error("Error: size < 2");
	std::vector<int> vector_sorted = m_vector;
	std::sort(vector_sorted.begin(), vector_sorted.end());
	int res = abs(*m_vector.begin() - *(m_vector.end() - 1));
	for (std::vector<int>::iterator it = m_vector.begin(); it + 1 != m_vector.end(); it++)
	{
		if (abs(*(it + 1) - *it) < res)
			res = abs(*(it + 1) - *it);
	}
	return abs(res);};

int Span::longestSpan() {
	if (m_vector.size() < 2)
		throw std::logic_error("Error: size < 2");
	std::vector<int>::iterator min = std::min_element(m_vector.begin(), m_vector.end());
	std::vector<int>::iterator max = std::max_element(m_vector.begin(), m_vector.end());
	return *max - *min; };
	
/* -----------------GETTERS-----------------*/
std::vector<int> Span::getVector() const {
	return m_vector;
}
