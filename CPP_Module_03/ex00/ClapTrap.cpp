
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : m_name("Default"), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "ClapTrap default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "ClapTrap " << m_name << " constructed.\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << m_name << " destroyed.\n";
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : m_name(copy.m_name),
      m_hitPoints(copy.m_hitPoints),
      m_energyPoints(copy.m_energyPoints),
      m_attackDamage(copy.m_attackDamage)
{
    std::cout << "ClapTrap " << m_name << " copied.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        m_name = other.m_name;
        m_hitPoints = other.m_hitPoints;
        m_energyPoints = other.m_energyPoints;
        m_attackDamage = other.m_attackDamage;
    }
    std::cout << "ClapTrap assignment called for " << m_name << ".\n";
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (m_energyPoints <= 0 || m_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << m_name << " can't attack: ";
        if (m_hitPoints <= 0)
            std::cout << "no hit points left.\n";
        else
            std::cout << "no energy points left.\n";
        return;
    }

    --m_energyPoints;
    std::cout << "ClapTrap " << m_name << " attacks " << target
              << ", causing " << m_attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    m_hitPoints = m_hitPoints - amount;
    if (m_hitPoints < 0)
        m_hitPoints = 0;
    std::cout << "ClapTrap " << m_name << " takes " << amount << " damage! Remaining Hit Points: " << m_hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << m_name << " can't repair: no hit points left.\n";
        return;
    }
    if (m_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << m_name << " can't repair: no energy left.\n";
        return;
    }

    m_hitPoints += amount;
    --m_energyPoints;

    std::cout << "ClapTrap " << m_name << " repairs itself for " << amount
              << " Hit Points! Total Hit Points: " << m_hitPoints << "\n";
}
