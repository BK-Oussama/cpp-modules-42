
#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
    Zombie *DozenZombies;

    DozenZombies = new Zombie[N];

    int i = 0;
    while (i < N)
    {
        DozenZombies[i].Set_Zombie_Name(name);
        i++;
    }

    return DozenZombies;
}