#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {

protected:
    std::string Name;
    unsigned int Hit;
    unsigned int Energy;
    unsigned int Attackp;
public:
    ClapTrap();
    ClapTrap(const std::string& Name);
    ~ClapTrap();
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator =(const ClapTrap &other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

}       ;

#endif