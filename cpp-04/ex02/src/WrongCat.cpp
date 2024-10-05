#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat Copy Constructor Called!" << std::endl;
	if (this != &other)
		*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat Copy Assigment Contructor Called!" << std::endl;
	type = other.getType();
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "# * WrongCat Sound !!! * #" << std::endl;
}

