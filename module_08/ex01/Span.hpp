#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &src);
	~Span();
	Span & operator = (const Span &rhs);
	void addNumber(int value);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();	
	std::vector<int> getVector() const;

private:
	Span();
	std::vector<int> m_vector;
	unsigned int m_size;
};