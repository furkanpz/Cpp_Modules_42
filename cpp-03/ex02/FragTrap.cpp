#include "FragTrap.hpp"


FragTrap::FragTrap()
{
    this->Hit = 100;
    this->Energy = 100;
    this->Attackp = 30;
    this->Name = "Unnamed";
    std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
    std::cout << "FragTrap Constructor Called" << std::endl;
    this->Hit = 100;
    this->Energy = 100;
    this->Attackp = 30;
    this->Name = name;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Copy Assigment Constructor Called" << std::endl;
    this->Name = other.Name;
    this->Hit = other.Hit;
    this->Attackp = other.Attackp;
    this->Energy = other.Energy;
    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;

    std::cout << "FragTrap " << this->Name << " attacks " << target
    <<  ", causing "  << this->Attackp << " points of damage!" << std::endl;
    this->Energy -= 1;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;
    std::cout << "FragTrap " << this->Name << " Repaired " <<
    amount << " Point!" << std::endl;
    this->Hit += amount;
    this->Energy -= 1;
}

void FragTrap::highFivesGuys(void)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;
    std::cout << "FragTrap " << this->Name << " High Fives Guys!" << std::endl;
    this->Energy -= 1;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;
    std::cout << "FragTrap " << this->Name << " "
    << amount << " Damaged!" << std::endl;
    if (this->Hit < amount)
        this->Hit = 0;
    else
        this->Hit -= amount;
}
