
#include "Cat.hpp"

Cat::Cat()
{
    m_type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructed\n";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destroyed\n";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    brain = new Brain(*copy.brain);
    std::cout << "Cat copied\n";
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        m_type = other.m_type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow!\n";
}
