#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default Constructor Called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called!" << std::endl;
}

Animal &Animal::operator = (const Animal &other)
{
	std::cout << "Animal Copy Assigment Constructor Called!" << std::endl;
	this->type = other.getType();
	return (*this);
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy Constructor Called!" << std::endl;
	*this = other;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

void Animal::makeSound() const
{
	std::cout << "# * Animall!!!! * #" << std::endl;
}