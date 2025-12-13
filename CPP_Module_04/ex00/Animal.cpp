
#include "Animal.hpp"

Animal::Animal() : m_type("Animal")
{
    std::cout << "Animal created\n";
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        m_type = other.m_type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed\n";
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return m_type;
}
