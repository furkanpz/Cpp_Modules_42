#include "iter.hpp"


template <typename T>
void print(T const &x) {
    std::cout << x << " ";
}

template <typename T>
void print(T &x) {
    std::cout << x << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    char arr2[] = {'a', 'b', 'c', 'd', 'e'};
    const int arr3[] = {6, 7, 8, 9, 10};
    const char arr4[] = {'f', 'g', 'h', 'i', 'j'};

    iter(arr, 5, print);
    iter(arr2, 5, print);
    iter(arr3, 5, print);
    iter(arr4, 5, print);
    return 0;
}