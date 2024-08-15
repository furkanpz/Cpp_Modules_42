#include "Zombie.hpp"


int main()
{
	Zombie *p;


	p = Zombie::zombieHorde(5,"TEST");
	for (int x = 0; x < 5; x++)
	{
		p[x].announce();
	}
		
	delete[] p;
}