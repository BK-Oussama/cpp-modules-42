
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "FragTrap default constructor called.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "FragTrap " << m_name << " constructed.\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << m_name << " destroyed.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap " << m_name << " copied.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap assignment called for " << m_name << ".\n";
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (m_energyPoints <= 0 || m_hitPoints <= 0)
    {
        std::cout << "FragTrap " << m_name << " can't attack: ";
        if (m_hitPoints <= 0)
            std::cout << "no hit points left.\n";
        else
            std::cout << "no energy points left.\n";
        return;
    }

    --m_energyPoints;
    std::cout << "FragTrap " << m_name << " blasts " << target
              << ", causing " << m_attackDamage << " points of damage!\n";
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << m_name << " High fives all around !\n";
}
