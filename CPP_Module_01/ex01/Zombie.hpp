
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{

private:
    std::string m_name;

public:
    Zombie();
    void announce(void);
    void set_Zombie_Name(std::string name);
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif
