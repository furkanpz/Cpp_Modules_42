#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor Called!" << std::endl;
	*this = other;
}

Brain &Brain::operator = (const Brain &other)
{
	std::cout << "Brain Copy Assigment Constructor Called!" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.getIdea(i);
	return (*this);
}

void Brain::setIdea(const std::string &idea, int index)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}