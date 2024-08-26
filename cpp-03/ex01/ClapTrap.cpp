#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
	this->name = name;
	this->hit = 10;
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
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
	this->name = "Unnamed";
	this->hit = 10;
	this->energy = 10;
	this->attackp = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &trap)
{
	std::cout << "ClapTrap Copy Asignment Constructor Called" << std::endl;
	this->name = trap.name;
	this->hit = trap.hit;
	this->energy = trap.energy;
	this->attackp = trap.attackp;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hit == 0 || this->energy == 0)
		return ;
	std::cout << "ClapTrap " << this->name << " attacks " 
	<< target << ", causing "<< this->attackp << " points of damage!"
	<< std::endl;
	this->hit -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit == 0 || this->energy == 0)
		return ;
	if (amount > this->hit)
		this->hit = 0;
	else
		this->hit = this->hit - amount;
	std::cout << "ClapTrap " << this->name << " " <<
	amount << " Take Damage Total Hit " << this->hit << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit == 0 || this->energy == 0)
		return ;
	this->hit -= 1;
	this->hit += amount;
	std::cout << "ClapTrap " << this->name << " " <<
	amount << " Repaired Total Hit " << this->hit << std::endl;
}

std::string ClapTrap::getName()
{
	return (this->name);
}

unsigned int ClapTrap::getHit()
{
	return (this->hit);
}


unsigned int ClapTrap::getEnergy()
{
	return (this->energy);
}

unsigned int ClapTrap::getAttackp()
{
	return (this->attackp);
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

void ClapTrap::setHit(unsigned int hit)
{
	this->hit = hit;
}

void ClapTrap::setEnergy(unsigned int energy)
{
	this->energy = energy;
}

void ClapTrap::setAttackp(unsigned int attackp)
{
	this->attackp = attackp;
}

