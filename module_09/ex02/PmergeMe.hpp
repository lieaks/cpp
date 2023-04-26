#pragma once

#ifndef PMERGEME_HPP 
#define PMERGEME_HPP 

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	PmergeMe();
public:	
	template <typename T> void insertion_sort(T& container);
};

#endif //PMERGEME_HPP 