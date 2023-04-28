#pragma once

#ifndef PMERGEME_HPP 
#define PMERGEME_HPP 

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

class PmergeMe
{
private:
	PmergeMe(const PmergeMe &);
	PmergeMe& operator = (const PmergeMe &);

public:	
	PmergeMe(int ac, char **av);
	~PmergeMe();

	template <typename T> void insertion_sort(T& container);
	template <typename T> T sort(T& container);
	template <typename T> void printContainer(T& container);
	void parse_arg(std::string av);
	class CustomException : public std::exception {
		private:
			const char* m_message;
		public:
			CustomException(const char * message) : m_message(message) {};
			virtual const char* what() const throw() {return m_message;};
	};
};
#endif //PMERGEME_HPP