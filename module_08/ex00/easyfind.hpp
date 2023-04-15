#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
void easyfind(T& container , int value){
	typename T::iterator pos = std::find(container.begin(), container.end(), value);
	if (pos == container.end())
		std::cout << value << " not found" << std::endl;
	else
		std::cout << value << " found" << std::endl;
};