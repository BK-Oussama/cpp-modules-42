
#include "Zombie.hpp"

int main()
{
    Zombie *ZO;

    int num_zombie = 3;
    ZO = zombieHorde(num_zombie, "Zooo");

    int i = 0;
    while (i < num_zombie)
    {
        ZO[i].announce();
        i++;
    }
    delete[] ZO;

    return (0);
}