#include "PmergeMe.hpp"

PmergeMe::PmergeMe () {};

template <typename T> void insertion_sort(T& container)
{
	for(std::size_t j = 1; j < container.size(); j++)
	{
	  int key = container[j];
	  int i = j-1;

	  while(i >= 0 && container[i] > key)
	  {
		 container[i+1] = container[i];
		 i--;
	  }
	  container[i+1] = key;
	}
};

template <typename T> void sort(T& container) 
{
	for(std::size_t i = 0; i + 1 < container.size(); i+=2)
	{
		if (container[i] < container[i + 1])	
			std::swap(container[i], container[i+1]);
	}
	T A_cont, B_cont;
	for(std::size_t i = 0; i + 1 < container.size(); i++)
	{
		if (i % 2 == 0)
			A_cont.push_back(container[i]);
		else
			B_cont.push_back(container[i]);
	}
	insertion_sort(A_cont);
	while (A_cont.size() != container.size())
	{
		A_cont.push_back(B_cont.front());
		B_cont.pop_back();
		insertion_sort(A_cont);
	}
	for(std::size_t i = 0; i + 1 < container.size(); i++)
	{
		std::cout < A_cont[i] << std::endl;
	}
}
