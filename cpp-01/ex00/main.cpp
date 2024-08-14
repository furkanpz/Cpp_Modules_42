#include "Zombie.hpp"


int main()
{
	Zombie a;
	Zombie *p;
	a.randomChump("TATA");
	p = Zombie::newZombie("TUTU");

	p->announce();
}