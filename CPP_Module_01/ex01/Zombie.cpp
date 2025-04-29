
#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::Set_Zombie_Name(std::string name)
{
    m_name = name;
}

// Zombie::~Zombie()
// {
//     announce();
// }