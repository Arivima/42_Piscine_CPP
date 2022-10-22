#ifndef TEMPLATE_H
#define TEMPLATE_H

# include <iostream>
# include <string>

template <typename T, typename U >
void iter(T* arr, int size, U& f)
{
	for (int i = 0; i < size; i++)
		f(arr[i]);
	return;
}

template <typename T>
void printN(T& n)
{
	std::cout << n << std::endl;
	return;
}

template <typename T>
void incr(T& n)
{
	n += 1;
	return;
}

template <typename T>
void addself(T& n)
{
	n += n;
	return;
}

#endif