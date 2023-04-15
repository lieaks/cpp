#include "Span.hpp"

Span::Span() {};

Span::Span(unsigned int n) : m_vector(0), m_size(n) {};

Span::Span(const Span &src) {
	*this = src;};

Span::~Span() {};

Span& Span::operator= (const Span &rhs) {
	if (this != &rhs)
	{
		m_vector = rhs.m_vector;
		m_size = rhs.m_size;
	}
	return *this; };

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
	int res = abs(*m_vector.begin() - *(m_vector.end() - 1));
	for (std::vector<int>::iterator it = m_vector.begin(); it + 1 != m_vector.end(); it++)
	{
		for (std::vector<int>::iterator it2 = it + 1; it2 != m_vector.end(); it2++)
		{
			if (abs(*it - *it2) < res)
				res = abs(*it - *it2);
		}
	}
	return abs(res); };

int Span::longestSpan() {
	if (m_vector.size() < 2)
		throw std::logic_error("Error: size < 2");
	std::vector<int>::iterator min = m_vector.begin();
	std::vector<int>::iterator max = m_vector.begin();
	for (std::vector<int>::iterator it = m_vector.begin(); it != m_vector.end(); it++)
	{
		if (*it < *min)
			min = it;
		if (*it > *max)
			max = it;
	}
	return abs(*min - *max); };
	

std::vector<int> Span::getVector() const {
	return m_vector;
}
