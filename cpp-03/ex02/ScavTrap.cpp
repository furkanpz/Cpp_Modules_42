#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{
    this->Hit = 100;
    this->Energy = 20;
    this->Attackp = 20;
    this->Name = "Unnamed";
    std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
    // BURADAKİ OUT DÜZELTİLİCEK
    std::cout << "ScavTrap Constructor Called" << std::endl;
    this->Hit = 100;
    this->Energy = 20;
    this->Attackp = 20;
    this->Name = name;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy Constructor Called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy Assigment Constructor Called" << std::endl;
    this->Name = other.Name;
    this->Hit = other.Hit;
    this->Attackp = other.Attackp;
    this->Energy = other.Energy;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;

    std::cout << "ScavTrap " << this->Name << " attacks " << target
    <<  ", causing "  << this->Attackp << " points of damage!" << std::endl;
    this->Energy -= 1;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;
    std::cout << "ScavTrap " << this->Name << " Repaired " <<
    amount << " Point!" << std::endl;
    this->Hit += amount;
    this->Energy -= 1;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;
    std::cout << "ScavTrap " << this->Name << " "
    << amount << " Damaged!" << std::endl;
    if (this->Hit < amount)
        this->Hit = 0;
    else
        this->Hit -= amount;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " have enterred in Gate keeper mode" << std::endl;
}