#include "PhoneBook.hpp"

int main()
{
	PhoneBook a;
	std::string input;

	while (1)
	{
		std::cout << "1 - Add" << std::endl << "2 - Search" << std::endl << "3 - Exit" << std::endl;
		std::cout << "> ";
		getline(std::cin, input);
		if (std::cin.eof() == 1)
			break;
		if (input.empty())
			continue;
		if (input.size() != 1 || (input.size() == 1 && (input[0] - '0' > 3 || input[0] - '0' <= 0)))
		{
			std::cout << "Choose between 1 - 3" << std::endl;
			continue;
		}
		if (input[0] == '1')
			a.Add();
		else if (input[0] == '2')
			a.Search();
		else if (input[0] == '3')
			a.Exit();
	}
}