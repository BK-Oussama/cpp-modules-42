
#include "Zombie.hpp"


Zombie::Zombie(std::string name) : m_name(name){}

void Zombie::announce(void)
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::announceDeath(void)
{
    std::cout << m_name << ": is dead ..." << std::endl;

}

Zombie *newZombie(std::string name)
{
    Zombie *new_zombie;

    new_zombie = new Zombie(name);
    return (new_zombie);
}

void randomChump( std::string name)
{
    Zombie Champ(name);
    Champ.announce();
}

Zombie::~Zombie()
{
    announceDeath();
}