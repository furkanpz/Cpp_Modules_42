#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string Name )
{
	Zombie *ret;

	ret = new Zombie(Name);
	return (ret);
}