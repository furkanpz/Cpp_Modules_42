#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::ifstream file(av[1]);
	if (file.fail())
	{
		std::cerr << "Error: could not open file: " << av[1] << std::endl;
		return 1; 
	}
	
}