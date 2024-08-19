#include "Zombie.hpp"


int main()
{
	Zombie *p = NULL;
	Zombie a("testo");
	p = a.newZombie("p");
	p->announce();
	p->randomChump("test");
	a.randomChump("yeey");
	delete p;
}