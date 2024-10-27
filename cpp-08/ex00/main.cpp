#include "easyfind.hpp"
#include <vector>
#include <list>



int main() {
	std::list<int> v;
	std::list<int>::iterator i;

	i = v.begin();
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	   for (int x = 0; x < v.size(); x++) {
        std::cout << &*i << " - " << *i++ << " " << std::endl;
    }
	v.push_front(6);
	std::cout << "------" << std::endl;
	i = v.begin();
	for (int x = 0; x < v.size(); x++) {
        std::cout << &*i << " - " << *i++ << " " << std::endl;
    }
	return 0;
}