#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("Test", 5);
	Form b("Form", false, 151,3);
	
	b.beSigned(a);
	a.signForm(b);
}