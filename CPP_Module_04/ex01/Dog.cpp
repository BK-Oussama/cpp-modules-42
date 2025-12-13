
#include "Dog.hpp"

Dog::Dog()
{
    m_type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructed\n";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed\n";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    brain = new Brain(*copy.brain);
    std::cout << "Dog copied\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        m_type = other.m_type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "33333ee, attack le !!\n";
}
