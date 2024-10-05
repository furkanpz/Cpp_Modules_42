#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->_Brain = new Brain();
	std::cout << "Cat Default Constructor Called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called!" << std::endl;
	delete this->_Brain;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy Constructor Called!" << std::endl;
	if (this != &other)
		*this = other;
	this->_Brain = new Brain(*other._Brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy Assigment Constructor Called!" << std::endl;
	if (this != &other)
	{
		this->type = other.getType();
		delete this->_Brain;
		this->_Brain = new Brain(*other._Brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "# * Meow Meow!!!! * #" << std::endl;
}
