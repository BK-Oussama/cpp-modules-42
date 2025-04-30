#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>

class HumanA{
    
    private:
    std::string m_name;
    Weapon &m_weapon;

    public:
    HumanA(const std::string &name, Weapon &weapon);
    void attack()const;
};

#endif