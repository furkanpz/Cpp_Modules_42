#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("Test", 5);
	Form b("Form", false, 4,3);
	
	b.beSigned(a);
	a.signForm(b);
	std::cout << b << std::endl;

}