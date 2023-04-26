#include "PmergeMe.hpp"

template <typename T> void PmergeMe::insertion_sort(T& container)
{
    for(std::size_t j = 1; j < container.size(); j++)
    {
      T::iterator key = vec[j];
      int i = j-1;

      while(i >= 0 && vec[i] > key)
      {
         vec[i+1] = vec[i];
         i--;
      }
      vec[i+1] = key;
    }
};