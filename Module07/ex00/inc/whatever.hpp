#pragma once

template<typename T>

const T &max(const T &x, const T &y)
{
	return (x >= y ? x : y);
}

template<typename T>

const T &min(const T &x, const T &y)
{
	return (x <= y ? x : y);
}

template<typename T>

void swap(T &x, T &y)
{
	T	tmp = x;

	x = y;
	y = tmp;
}
