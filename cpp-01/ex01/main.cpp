#include "Zombie.hpp"


int main()
{
	Zombie *p;


	p = Zombie::zombieHorde(5,"TEST"); 
	
	delete[] p;
}