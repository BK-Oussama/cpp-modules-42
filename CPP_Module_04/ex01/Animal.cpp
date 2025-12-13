
#include "Animal.hpp"

Animal::Animal() : m_type("Animal")
{
    std::cout << "Animal constructed\n";
}

Animal::~Animal()
{
    std::cout << "Animal destroyed\n";
}

Animal::Animal(const Animal &copy)
{
    m_type = copy.m_type;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        m_type = other.m_type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return m_type;
}
