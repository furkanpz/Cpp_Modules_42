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
	std::string quest[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
 	AForm*    forms[] = {
        new RobotomyRequestForm( target ),
        new PresidentialPardonForm( target ),
        new ShrubberyCreationForm( target )
    };
	AForm *ret;
	ret = NULL;
	for (int x = 0; x < 3; x++)
	{
		if (quest[x] == name)
			ret = forms[x];
		else
			delete forms[x];
	}
	if (ret != NULL)
		std::cout << "Intern creates " << name << std::endl;
	else
		std::cout << "Intern was not able to find the form " << name << std::endl;
	return (NULL);
}

const char *Intern::EmptyTargetException::what() const throw()
{
    return ("Target is empty!");
}

const char *Intern::NoFormException::what() const throw()
{
    return ("No form named that !");
}