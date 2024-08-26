#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{

	public:
		ScavTrap(std::string name);
		ScavTrap();
		ScavTrap(ScavTrap &trap);
		ScavTrap& operator = (ScavTrap &trap);
		~ScavTrap();
		void guardGate();
};

#endif