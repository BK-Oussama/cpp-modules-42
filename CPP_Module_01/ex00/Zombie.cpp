
#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::Set_Zombie_Name(std::string name)
{
    m_name = name;
}

Zombie *new_Zombie(std::string name)
{
    Zombie *new_zombie;

    new_zombie = new Zombie();
    new_zombie->Set_Zombie_Name(name);
    return (new_zombie);
}


void randomChump( std::string name)
{
    Zombie Champ;

    Champ.Set_Zombie_Name(name);
    Champ.announce();
}

Zombie::~Zombie()
{
    announce();
}