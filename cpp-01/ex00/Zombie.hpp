#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie {
	private:
		std::string Name;

	public:
		void announce( void );
		Zombie* newZombie( std::string Name );
		void randomChump( std::string Name );
		Zombie();
		Zombie(std::string Name);
		~Zombie ();
};
#endif