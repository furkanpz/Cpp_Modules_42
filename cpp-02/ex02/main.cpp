#include "Fixed.hpp"


int main()
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a < b)
		std::cout << b / a << std::endl;
	return 0;
}