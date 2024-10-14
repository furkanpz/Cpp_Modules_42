#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Unnamed"), grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Default Destructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	std::cout << "Bureaucrat Copy Constructor Called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy Assigment Constructor Called!" << std::endl;
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too Low!");
}
