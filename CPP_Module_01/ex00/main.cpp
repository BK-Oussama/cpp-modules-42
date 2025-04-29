
#include "Zombie.hpp"

int main()
{
    Zombie NewZombie;
    NewZombie.Set_Zombie_Name("Namrod");
    NewZombie.announce();

    Zombie *Zombie_01;

    Zombie_01 = new_Zombie("Jared");
    Zombie_01->announce();
    delete Zombie_01;

    randomChump("Walking dead");
    return 0;
}