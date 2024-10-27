#ifndef EASYFIND_HPP
# define EASYFIND_HPP


#include <iostream>


class EasyFindException : public std::exception {

	public:
		virtual const char *what() const throw(){
			return ("Not found the element you are looking for!");
		}
};

template <typename T>
typename T::iterator easyfind(T& a, int b)
{
	typename T::iterator ret;

	ret = std::find(a.begin(), a.end(), b);
	if (ret != a.end())
		return (ret);
	else
		throw EasyFindException();
}

#endif
