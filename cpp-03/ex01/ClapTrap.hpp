#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

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
		ClapTrap();
		ClapTrap(const ClapTrap &trap);
		ClapTrap& operator = (const ClapTrap &trap);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName();
		unsigned int getHit();
		unsigned int getEnergy();
		unsigned int getAttackp();
		void setName(std::string name);
		void setHit(unsigned int hit);
		void setEnergy(unsigned int energy);
		void setAttackp(unsigned int attackp);
}			;

#endif