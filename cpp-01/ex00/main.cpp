#include "Zombie.hpp"


int main()
{
	Zombie *p = NULL;
	Zombie a("nonptr");
	p = a.newZombie("ptr");
	p->announce();
	a.announce();
	p->randomChump("ptrrandom");
	a.randomChump("nonptr random");
	delete p;
}