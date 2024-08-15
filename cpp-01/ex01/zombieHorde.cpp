#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
    Zombie *Zombies;
    
    Zombies = new Zombie[N];
    for (int x = 0; x < N; x++)
        Zombies[x].SetName(name);
    return (Zombies);
}