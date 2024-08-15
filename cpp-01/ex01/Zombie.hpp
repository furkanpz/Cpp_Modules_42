#pragma once

#include <iostream>
#include <string>


class Zombie {
	private:
		std::string Name;

	public:
		void announce( void );
		Zombie();
		Zombie(std::string Name);
		~Zombie ();
		void SetName(std::string name);
		static Zombie* zombieHorde( int N, std::string name );
};