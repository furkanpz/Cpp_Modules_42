#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

static void	test_intern(const std::string &type, const std::string &target)
{
	Intern		bob;
	AForm		*form;
	Bureaucrat	jim("Jim", 1);

	form = bob.makeForm(type, target);
	if (form)
	{
		std::cout << *form << std::endl;
		jim.signForm(*form);
		form->execute(jim);
	}
	delete (form);
}

int	main()
{
	test_intern("shrubbery creation", "garden");
	std::cout << "----------------------------------" << std::endl;
	test_intern("robotomy request", "Bender");
	std::cout << "----------------------------------" << std::endl;
	test_intern("presidential pardon", "Tom");
	std::cout << "----------------------------------" << std::endl;
	test_intern("unknown form", "target");
	std::cout << "----------------------------------" << std::endl;
	test_intern("test", "lol");
	std::system("leaks Intern");
	return (0);
}