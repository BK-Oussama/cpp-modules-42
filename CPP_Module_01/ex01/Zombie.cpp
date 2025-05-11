
#include "Zombie.hpp"

Zombie::Zombie() : m_name("") {}

void Zombie::announce(void)
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_Zombie_Name(std::string name)
{
    m_name = name;
}
