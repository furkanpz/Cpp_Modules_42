#include <iostream>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int a = std::rand();

	if (a % 3 == 0)
		return new A;
	else if (a % 3 == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "This is A" << std::endl;
	B *b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "This is B" << std::endl;
	C *c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "This is C" << std::endl;
}
void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "This is A" << std::endl;
	}
	catch (std::bad_cast)
	{}
	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "This is B" << std::endl;
	}
	catch (std::bad_cast)
	{}
	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "This is C" << std::endl;
	}
	catch (std::bad_cast)
	{}
}

int main()
{
	Base *p = new B();

	identify(*p);
}