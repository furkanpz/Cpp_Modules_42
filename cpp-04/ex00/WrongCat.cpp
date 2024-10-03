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
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	type = other.getType();
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "# * Animalll !!! * #" << std::endl;
}

