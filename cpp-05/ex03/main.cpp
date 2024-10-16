#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat b("Bureaucrat", 1);
	Intern caktirma = Intern();

	AForm *f4 = caktirma.makeForm("ShrubberyCreationForm", "test");

}