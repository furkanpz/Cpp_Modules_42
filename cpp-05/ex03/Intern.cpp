#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called!" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Intern Copy Constructor Called!" << std::endl;
	if (this != &src)
		*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called!" << std::endl;
}

Intern & Intern::operator=(Intern const & src)
{
	std::cout << "Intern Copy Assigment Constructor Called!" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	if (name == "ShrubberyCreationForm")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (name == "RobotomyRequestForm")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (name == "PresidentialPardonForm")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	}
	else
	{
		std::cout << "Intern cannot create " << name << std::endl;
		return NULL;
	}
}