#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " is born!" << std::endl;
	this->setHit(100);
	this->setEnergy(50);
	this->setAttackp(20);
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap is born!" << std::endl;
	this->setHit(100);
	this->setEnergy(50);
	this->setAttackp(20);
}

ScavTrap::ScavTrap(ScavTrap &trap)
{
	std::cout << "ScavTrap " << trap.getName() << " is born!" << std::endl;
	*this = trap;
}

ScavTrap& ScavTrap::operator = (ScavTrap &trap)
{
	ClapTrap::operator=(trap);
	std::cout << "ScavTrap " << trap.getName() << " is born!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " have enterred in Gate keeper mode!" << std::endl;
}