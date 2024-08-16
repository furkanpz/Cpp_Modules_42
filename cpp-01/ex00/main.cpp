#include "Zombie.hpp"


int main()
{
	Zombie *p;

	p = p->newZombie("deneme");
	p->announce();
	p->randomChump("test");
	delete p;
}