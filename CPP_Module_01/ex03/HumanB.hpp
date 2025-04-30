#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

class HumanB{
    
    private:
    std::string m_name;
    Weapon *m_weapon;

    public:
    HumanB(const std::string &name);
    void setWeapon(Weapon &weapon);
    void attack()const;
};

#endif