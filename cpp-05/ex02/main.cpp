#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	srand(time(NULL));
	{
		ShrubberyCreationForm	form("garden");
		Bureaucrat				bob("Bob", 138);

		std::cout << "> " << form << std::endl;
		std::cout << "> " << bob << std::endl;
		bob.signForm(form);
		bob.executeForm(form);
		std::cout << "> Incrementing " << bob.getName() << "'s grade" << std::endl;
		bob.incrementGrade();
		bob.executeForm(form);
	}
	std::cout << "----------------------------------" << std::endl;
	{
		RobotomyRequestForm		form("target2");
		Bureaucrat				jim("Jim", 30);

		jim.signForm(form);
		jim.executeForm(form);
	}
	std::cout << "----------------------------------" << std::endl;
	{
		PresidentialPardonForm	form("target3");
		Bureaucrat				tom("Tom", 2);

		tom.signForm(form);
		tom.executeForm(form);
	}
	return (0);
}