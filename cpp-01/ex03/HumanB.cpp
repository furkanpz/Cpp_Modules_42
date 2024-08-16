#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->weapon = nullptr;
	this->name = name;
}

void HumanB::attack()
{
	if (!weapon)
		std::cout << this->name << " attacks with their "
		<< "Hands" << std::endl;
	else
		std::cout << this->name << " attacks with their "
	<< weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}