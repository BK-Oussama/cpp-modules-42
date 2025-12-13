
#include "Dog.hpp"


Dog::Dog()
{
    m_type = "Dog";
    std::cout << "Dog created\n";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copied\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const
{
    std::cout << "33333ee, attack le !!\n";
}
