
#include "Zombie.hpp"

int main()
{
    Zombie *ZO;

    int num_zombie = 3;
    ZO = zombieHorde(num_zombie, "Zooo");

    std::cout << "first zombie elment on the array\n";
    ZO[0].announce();
    std::cout << std::endl;

    int i = 0;
    while (i < num_zombie)
    {
        ZO[i].announce();
        i++;
    }

    delete[] ZO;
    return (0);
}
