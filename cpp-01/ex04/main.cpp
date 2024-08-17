#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "using: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cout << av[1] << ": Error opening the file!" << std::endl;
		return (1);
	}
	std::ofstream replace(std::string(av[1]) + ".replace");
	if (!replace.is_open())
	{
		std::cout << std::string(av[1]) + ".replace" << ": Error opening the file!" << std::endl;
		return (1);
	}

	std::string line;

    while (std::getline(file,line))
        replace << replace_in_line(line,av[2],av[3]);
	
	return 0;
}