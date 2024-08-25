#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
	this->name = name;
	this->hit = 0;
	this->energy = 10;
	this->attackp = 0;
}

ClapTrap::ClapTrap(const ClapTrap &trap)
{
	std::cout << "ClapTrap Copy Constructor Called" << std::endl;
	this->name = trap.name;
	this->hit = trap.hit;
	this->energy = trap.energy;
	this->attackp = trap.attackp;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &trap)
{
	std::cout << "ClapTrap Copy Asignment Constructor Called" << std::endl;
	this->name = trap.name;
	this->hit = trap.hit;
	this->energy = trap.energy;
	this->attackp = trap.attackp;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->name << " attacks " 
	<< target << ", causing "<< this->attackp << " points of damage!";
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}