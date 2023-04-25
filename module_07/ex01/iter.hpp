#pragma once

#include <iostream>

template <typename R, typename T, typename F>
void iter(R *array, size_t size, F (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename R, typename T, typename F>
void iter(R *array, size_t size, F (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

// template <typename T>
// void print(T &a)
// {
// 	std::cout << a << std::endl;
// }