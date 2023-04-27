#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(const PmergeMe &) {};
PmergeMe& PmergeMe::operator = (const PmergeMe &){return *this;};

PmergeMe::PmergeMe (int ac, char **av) {
	std::vector<int> vec;
	std::deque<int> deq;
	
	for (int i = 1; i < ac; i++)
	{
		parse_arg(av[i]);
		vec.push_back(atoi(av[i]));
		deq.push_back(atoi(av[i]));
	}
	std::cout << "Before:  ";
	printContainer(vec);

	// VECTOR
	clock_t start = clock();
	vec = sort(vec);
	clock_t end = clock();
	double vec_time = (end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000);
	//DEQUE
	start = clock();
	deq = sort(deq);
	end = clock();
	double deq_time = (end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000);

	std::cout << "After:   "; 
	printContainer(vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vec_time << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << deq_time << std::endl;

}

template <typename T> void PmergeMe::insertion_sort(T& container)
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
}

template <typename T> T PmergeMe::sort(T& container) 
{
	for(std::size_t i = 0; i + 1 < container.size(); i+=2)
	{
		if (container[i] < container[i + 1])	
			std::swap(container[i], container[i+1]);
	}
	T A_cont, B_cont;
	for(std::size_t i = 0; i < container.size(); i++)
	{
		if (i % 2 == 0)
			B_cont.push_back(container[i]);
		else
			A_cont.push_back(container[i]);
	}
	insertion_sort(A_cont);
	while (A_cont.size() != container.size())
	{
		A_cont.push_back(B_cont.back());
		B_cont.pop_back();
		insertion_sort(A_cont);
	}
	return A_cont;
}

template <typename T> void PmergeMe::printContainer(T& container){
	for (typename T::iterator it = container.begin(); it != container.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::parse_arg(std::string av) {
	if (av.size() == 0)
		throw CustomException("Error");
	for (size_t i = 0; i < av.size(); i++){
		if (!isdigit(av[i]))
			throw CustomException("Error");
	};
	if (atol(av.c_str()) > INT_MAX)
		throw CustomException("Error");
}