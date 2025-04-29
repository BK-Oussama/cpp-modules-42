
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
class Zombie{

    private:
        std::string m_name;

    public:
        void announce(void);
        void Set_Zombie_Name(std::string name);
        ~Zombie();
        // Zombie *new_Zombie(std::string name);
};

Zombie *new_Zombie(std::string name);

void randomChump( std::string name );

#endif
