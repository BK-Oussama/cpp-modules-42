

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
    : m_name(name), m_weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon)
{
    m_weapon = &weapon;
}

void HumanB::attack() const
{
    if (m_weapon)
        std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}
