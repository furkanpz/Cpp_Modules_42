#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		Form		form("form1", 10, 3);
		Bureaucrat	bob("bob", 11);
		Bureaucrat	jim("jim", 9);

		std::cout << form << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		std::cout << jim << std::endl;
		jim.signForm(form);
		std::cout << form << std::endl;
	}
	std::cout << "------------" << std::endl;
	{
		Form		*form2 = new Form("form2", 50, 50);
		Bureaucrat	lily("lily", 2);

		std::cout << *form2 << std::endl;
		std::cout << lily << std::endl;
		std::cout << "> Signing form '" << form2->getName() << "' with " << lily.getName() << std::endl;
		form2->beSigned(lily);
		std::cout << *form2 << std::endl;

		delete (form2);
	}
	return (0);
}