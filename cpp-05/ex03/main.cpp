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

	test_intern("robotmy request", "Bender");
	std::cout << "-----------------" << std::endl;
	test_intern("presidential pardon", "Bender");
	std::cout << "-----------------" << std::endl;
	test_intern("shrubbery creation", "Bender");
	std::cout << "-----------------" << std::endl;
	test_intern("test creation", "Bender");
	std::cout << "-----------------" << std::endl;
	try{
		test_intern("", "asdasdasd");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}