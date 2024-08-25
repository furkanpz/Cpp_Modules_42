#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap {

	private:
		std::string name;
		unsigned int hit;
		unsigned int energy;
		unsigned int attackp;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &trap);
		ClapTrap& operator = (const ClapTrap &trap);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
}			;

#endif