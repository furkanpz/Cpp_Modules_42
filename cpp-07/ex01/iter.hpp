#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *a, size_t len,void (*f)(T&))
{
	size_t i;

	for (i = 0; i < len; i++)
		f(a[i]);
}

#endif