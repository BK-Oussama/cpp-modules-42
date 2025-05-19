
#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "ScavTrap " << m_name << " constructed.\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << m_name << " destroyed.\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap " << m_name << " copied.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap assignment called for " << m_name << ".\n";
    return *this;
}


void ScavTrap::attack(const std::string &target)
{
    if (m_energyPoints <= 0 || m_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << m_name << " can't attack: ";
        if (m_hitPoints <= 0)
            std::cout << "no hit points left.\n";
        else
            std::cout << "no energy points left.\n";
        return;
    }

    --m_energyPoints;
    std::cout << "ScavTrap " << m_name << " slams " << target
              << ", causing " << m_attackDamage << " points of damage!\n";

}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode!\n";
}
