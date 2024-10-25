#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& a, int b)
{
	return std::find(a.begin(), a.end(), b);
} 	


#endif
