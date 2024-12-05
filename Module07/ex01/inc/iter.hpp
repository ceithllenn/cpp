#pragma once

#include <iostream>

template<typename T>

void iter(T *array, int len, void(*f)(T &))
{
	if (!array || !f)
		return ;
	for (int i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>

void display(T &t)
{
	std::cout << t << std::endl;
}