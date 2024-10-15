#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b("Bureaucrat", 1);
	Bureaucrat b2("Bureaucrat2", 150);
	AForm *f = new ShrubberyCreationForm("test");
	AForm *f2 = new RobotomyRequestForm("RobotomyRequestForm");
	AForm *f3 = new PresidentialPardonForm("PresidentialPardonForm");

	b.signForm(*f);
	b.signForm(*f2);

	b.executeForm(*f);
	b.executeForm(*f2);
	b.executeForm(*f3);
	

}