#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("Unnamed"), Hit(10), Energy(10), Attackp(0)
{
    std::cout << "Default Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default Destructor Called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy Assigment Constructor Called" << std::endl;
    this->Name = other.Name;
    this->Hit = other.Hit;
    this->Attackp = other.Attackp;
    this->Energy = other.Energy;
    return (*this);
}

ClapTrap::ClapTrap(const std::string &name) : Name(name), Hit(10), Energy(10), Attackp(0)
{
    // BURADAKİ OUT DÜZELTİLİCEK
    std::cout << "Default Constructor Called" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy Constructor Called" << std::endl;
    *this = other;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;
    std::cout << "ClapTrap " << this->Name << " Repaired " <<
    amount << " Point!" << std::endl;
    this->Hit += amount;
    this->Energy -= 1;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;

    std::cout << "ClapTrap " << this->Name << " attacks " << target
    <<  ", causing "  << this->Attackp << " points of damage!" << std::endl;
    this->Energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->Hit == 0 || this->Energy == 0)
        return ;
    std::cout << "ClapTrap " << this->Name << " "
    << amount << " Damaged!" << std::endl;
    if (this->Hit < amount)
        this->Hit = 0;
    else
        this->Hit -= amount;
}