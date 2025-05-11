
#include "Zombie.hpp"

int main()
{
 
    Zombie *Zombie_01;

    Zombie_01 = newZombie("Jared");
    Zombie_01->announce();
    delete Zombie_01;

    randomChump("Walking dead");
    return 0;
}