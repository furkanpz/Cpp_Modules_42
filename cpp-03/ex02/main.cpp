#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    ScavTrap Clap("Test");

    Clap.beRepaired(100);
    ClapTrap a = Clap;

    FragTrap b("FragTrap");
    b.highFivesGuys();
    b.attack("Enemy");
    b.beRepaired(123);
    a.attack("Enemy");
}