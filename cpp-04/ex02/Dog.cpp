#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->_Brain = new Brain();
	std::cout << "Dog Default Constructor Called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called!" << std::endl;
	delete this->_Brain;
}

Dog::Dog(const Dog &other)
{
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.getType();
	return (*this);
}


void Dog::makeSound() const
{
	std::cout << "# * Woof Woof !!!! * #" << std::endl;
}