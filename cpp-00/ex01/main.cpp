#include "PhoneBook.hpp"

int main()
{
	PhoneBook a;
	std::string input;

	while (1)
	{
		std::cout << "1 - ADD" << std::endl << "2 - SEARCH" << std::endl << "3 - EXIT" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof() == 1)
			break;
		if (input.empty())
			continue;
		if (input != "ADD" && input != "SEARCH" && input != "EXIT")
		{
			std::cout << "Please do not enter non-command input" << std::endl;
			continue;
		}
		if (input == "ADD")
			a.Add();
		else if (input == "SEARCH")
			a.Search();
		else if (input == "EXIT")
			a.Exit();
	}
}