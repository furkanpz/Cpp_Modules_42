#include "Zombie.hpp"

void Zombie::randomChump( std::string Name )
{
	Zombie zombie(Name);

	zombie.announce();
}