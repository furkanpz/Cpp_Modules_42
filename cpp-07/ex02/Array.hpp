#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T* data;
		unsigned int size;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &other);
		const Array & operator = (const Array &other);
		unsigned int Size() const;
		T &operator[](unsigned int n);
		class wrong_array : public std::exception {
			virtual const char *what() const throw();
		};
};

#include "Array.tpp"


#endif