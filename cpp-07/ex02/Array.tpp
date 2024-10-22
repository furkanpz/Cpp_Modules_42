#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    size = 0;
    data = new T[size];
}


template <typename T>
Array<T>::Array(unsigned int n)
{
    size = n;
    data = new T[n];
}
template <typename T>
unsigned int Array<T>::Size() const
{
    return (size);
}

template <typename T>
Array<T>::Array(const Array &other)
{
    if (data)
        delete data;
    size = other.Size();
    Data = new Data(other.data);
}