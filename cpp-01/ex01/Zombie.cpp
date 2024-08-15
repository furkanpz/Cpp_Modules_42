#include "Zombie.hpp"


void Zombie::announce( void )
{
	if (this->Name.empty())
		std::cout << "Unnamed: BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << this->Name << ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

Zombie::Zombie(std::string Name)
{
	this->Name = Name;
}
Zombie::Zombie() : Name("Unnamed")
{
	
}

Zombie::~Zombie() 
{
	std::cout << this->Name << " has been destroyed!" << std::endl;
}

void Zombie::SetName(std::string name)
{
	this->Name = name;
}