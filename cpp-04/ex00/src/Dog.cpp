#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog Copy Constructor Called!" << std::endl;
	if (this != &other)
		*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy Assigment Constructor Called!" << std::endl;
	this->type = other.getType();
	return (*this);
}


void Dog::makeSound() const
{
	std::cout << "# * Woof Woof !!!! * #" << std::endl;
}