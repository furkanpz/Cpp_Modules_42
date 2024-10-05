#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal Default Constructor Called!" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor Called!" << std::endl;
}

AAnimal &AAnimal::operator = (const AAnimal &other)
{
	std::cout << "AAnimal Copy Assigment Constructor Called!" << std::endl;
	this->type = other.getType();
	return (*this);
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal Copy Constructor Called!" << std::endl;
	if (this != &other)
		*this = other;
}

std::string AAnimal::getType() const
{
	return (this->type);
}

