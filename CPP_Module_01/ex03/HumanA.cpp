
#include "HumanA.hpp"
#include <cstddef>
#include <iostream>
HumanA::HumanA(const std::string &name, Weapon &weapon)
    : m_name(name), m_weapon(weapon){}

void HumanA::attack()const
{
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl; 
}

