#include "Zombie.hpp"


void Zombie::announce( void )
{
	std::cout << this->Name << ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

Zombie::Zombie(std::string Name)
{
	this->Name = Name;
}
Zombie::Zombie()
{
	
}

Zombie::~Zombie() 
{
	std::cout << this->Name << " has been destroyed!" << std::endl;
}