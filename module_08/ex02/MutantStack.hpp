#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack<T>() {};
	MutantStack<T>(const MutantStack<T> &) {};
	virtual ~MutantStack<T>() {};
	MutantStack<T> & operator = (const MutantStack<T> &) {};

	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	iterator begin() {return this->c.begin();};
	const_iterator begin() const {return this->c.begin();};
	iterator end() {return this->c.end();};
	const_iterator end() const {return this->c.end();};
};

#endif //MUTANTSTACK_HPP