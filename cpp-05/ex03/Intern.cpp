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
	if (target.empty())
		throw Intern::EmptyTargetException();
	if (name.empty())
		throw Intern::NoFormException();
	std::string quest[] = {"robotomy request","presidential pardon","shrubbery creation"};
	for (int x = 0; x < 3; x++)
	{
		if (name.compare(quest[x]) == 0)
		{
			std::cout << "Intern creates " << name << std::endl;
			switch (x)
			{
				case 0:
					return new RobotomyRequestForm(target);
				case 1:
					return new PresidentialPardonForm(target);
				case 2:
					return new ShrubberyCreationForm(target);
			}
		}
	}
	std::cout << "Intern was not able to find the form " << name << std::endl;
	return (NULL);
}

const char *Intern::EmptyTargetException::what() const throw()
{
    return ("Target is empty!");
}

const char *Intern::NoFormException::what() const throw()
{
    return ("No form named that!");
}