#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Test", 5);
	
	for (int x = 0; x < 7; x++)
	{
		try{
			a.incrementGrade();
			std::cout << a << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
}