#include "Zombie.hpp"

void Zombie::randomChump( std::string Name )
{
	Zombie zombie;

	zombie.Name = Name;
	zombie.announce();
}