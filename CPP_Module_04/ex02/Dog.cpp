
#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructed\n";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog copied\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "33333ee, attack le !!\n";
}
