#include "ScavTrap.hpp"


int main()
{
    ScavTrap Clap("Test");

    Clap.beRepaired(100);
    ClapTrap a = Clap;
    a.beRepaired(5);
    a.takeDamage(5);
    a.attack("Enemy");
}