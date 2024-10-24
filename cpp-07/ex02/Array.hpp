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
		Array(): size(0), data(new T[0]) {};
		Array(unsigned int n): size(n), data(new T[n]) {};
		Array(const Array &other): size(other.Size()), data(new T[other.Size()]) {
			for (unsigned int x= 0; x < other.Size(); x++)
				data[x] = other[x];
		};
		Array & operator = (const Array &other)
		{
			if (this != &other)
			{
				delete[] data;
				data = new T[other.Size()];
				size = other.Size();
				for (unsigned int x = 0; x < size; x++)
					data[x] = other[x];
			}
		};
		T &operator[](unsigned int n)
		{
			if (n >= size)
				throw wrong_array();
			return (data[n]);
		};
		const T &operator[](unsigned int n) const
		{
			if (n >= size)
				throw wrong_array();
			return (data[n]);
		};
		class wrong_array : public std::exception {
			virtual const char *what() const throw()
			{
				return ("Array Index Too Much!");
			}
		};
		~Array() {delete[] data;};

	public:
		unsigned int Size() const {return size; };
};

#endif