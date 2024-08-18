#include "PhoneBook.hpp"

int main()
{
	PhoneBook a;
	std::string input;
	int option;

	while (1)
	{
		std::cout << "1 - Add" << std::endl << "2 - Search" << std::endl << "3 - Exit" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof() == 1)
			break;
		if (input.empty())
			continue;
		try {
			option = std::stoi(input);
		}
		catch (std::invalid_argument) {
			std::cout << "Choose between 1 - 3" << std::endl;
			continue;
		}
		catch (std::out_of_range) {
			std::cout << "Choose between 1 - 3" << std::endl;
			continue;
		}
		if (option > 3 || option <= 0)
		{
			std::cout << "Choose between 1 - 3" << std::endl;
			continue;
		}
		if (option == 1)
			a.Add();
		else if (option == 2)
			a.Search();
		else if (option == 3)
			a.Exit();
	}
}