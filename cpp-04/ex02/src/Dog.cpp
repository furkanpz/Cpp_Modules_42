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
	std::cout << "Dog Copy Constructor Called!!" << std::endl;
	if (this != &other)
		*this = other;
	this->_Brain = new Brain(*other._Brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy Assigment Constructor Called!" << std::endl;
	if (this != &other)
	{
		this->type = other.getType();
		delete this->_Brain;
		this->_Brain = new Brain(*other._Brain);
	}
	return (*this);
}


void Dog::makeSound() const
{
	std::cout << "# * Woof Woof !!!! * #" << std::endl;
}