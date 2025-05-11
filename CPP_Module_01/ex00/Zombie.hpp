
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie{

    private:
        std::string m_name;

    public:
        Zombie(std::string name);
        void announce(void);
        void announceDeath(void);
        ~Zombie();

};

Zombie *newZombie(std::string name);

void randomChump( std::string name );

#endif
