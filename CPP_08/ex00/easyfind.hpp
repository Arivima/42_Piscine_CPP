#ifndef TEMPLATE_H
#define TEMPLATE_H

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

// supports lists<int>, vector<int>, deque<int>
template <typename T >
int easyfind(T& container, int n)
{
	typename	T::iterator			it;
	typename	T::iterator			begin	= container.begin();
	typename	T::iterator			end		= container.end();

	it = std::find(begin, end, n);

	if (it == end)
    {
		throw std::out_of_range("easyfind. Value not found.");
    }
	return *it;
}

#endif