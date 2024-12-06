#pragma once

#include <iostream>

template<typename T, typename Func>

void iter(T *array, int len, Func(T &))
{
	if (!array || !Func)
		return ;
	for (int i = 0; i < len; i++)
		Func(array[i]);
}

template <typename T>

void display(T &t)
{
	std::cout << t << std::endl;
}