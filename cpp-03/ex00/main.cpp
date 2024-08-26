#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("Test");
	b.attack("Test2");
	a.takeDamage(100);
	a.attack("Test");
	b.takeDamage(0);
	b.beRepaired(-5);
	b.attack("Test");
	b.attack("Test");
	a.attack("Test");
}