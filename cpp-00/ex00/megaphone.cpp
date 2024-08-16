#include <iostream>

char ifalpha(char c) 
{
	if (std::isalpha(c))
		return (std::toupper(c));
	return (c);
}

int main(int ac, char **av)
{

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int x = 1; x < ac; x++)
	{
		for (int a = 0; av[x][a]; a++)
		{
			av[x][a] = ifalpha(av[x][a]);
			std::cout << av[x][a];
		}
		if (x + 1 < ac)
			std::cout << " ";
	}
	std::cout << std::endl;
}