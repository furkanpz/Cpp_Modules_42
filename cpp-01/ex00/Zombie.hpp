#pragma once

#include <iostream>
#include <string>


class Zombie {
	private:
		std::string Name;

	public:
		void announce( void );
		static Zombie* newZombie( std::string Name );
		void randomChump( std::string Name );
		Zombie();
		Zombie(std::string Name);
		~Zombie ();
};