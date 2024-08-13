#include <iostream>

char functochar(char c, int (*func)(int)) {
    char result = func(c);
	return (result);
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
			if (std::isalpha(av[x][a]))
				av[x][a] = functochar(av[x][a], toupper);
			std::cout << av[x][a];
		}
		if (x + 1 < ac)
			std::cout << " ";
	}
	std::cout << std::endl;
}