#include "Zombie.hpp"


int main()
{
	Zombie a;
	Zombie *p;

	p = a.newZombie("deneme");
	delete p;
}