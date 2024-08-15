#include "Zombie.hpp"


int main()
{
	Zombie *p;

	p->randomChump("Test");
	p = Zombie::newZombie("TUTU");
	p->announce();
	delete p;
}