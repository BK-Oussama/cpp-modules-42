
#include "ClapTrap.hpp"

int main()
{
    ClapTrap player("Lalo");
    player.attack("mike");
  


    player.takeDamage(5);
    player.beRepaired(3);
    player.attack("gus");
    player.takeDamage(10);
    player.beRepaired(5);
    return 0;
}
