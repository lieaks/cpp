#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
void easyfind(T& container , int value){
	try
	{
		typename T::iterator pos = std::find(container.begin(), container.end(), value);
		if (pos == container.end())
			throw std::exception();
		else
			std::cout << value << " found" << std::endl;
	}
	catch (std::exception &e)
	{
			std::cerr << value << " not found" << std::endl;
	} 
};